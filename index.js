// ==UserScript==
// @name         牛客mark
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       lancercd
// @match        https://ac.nowcoder.com/acm/problem/*
// @grant        none
// ==/UserScript==


;
const MarkConfig_ = {
    key:{
        // 主组合键 'ctrlKey', 'shiftKey', 'altKey'  只支持该三个键
        main: ['shiftKey', 'altKey'],
        // 附 键
        keyCode : ['81', '83']
    },
    color: {
        backgroundColor: ['#e67e22', 'rgba(231, 76, 60,1.0)', 'rgba(52, 152, 219,1.0)'],
    },
};
class MarkNowCoder_{
    constructor(){
        this.init();
    }
    init(){
        this.getEle();
        this.bindEvent();
    }
    getEle(){
        this.el = document.getElementsByClassName('terminal-topic')[0];
        this.el.setAttribute('tabindex', 1);
    }
    bindEvent(){
        // document.body.onkeydown = this.eventHandle.bind(this);
        this.el.onkeydown = this.eventHandle.bind(this);
    }

    eventHandle(e){
        e = e || window.event;
        let opt = this.validateKey(e);
        if(opt > -1) this.deal(opt);

    }
    validateKey(e){
        let flag = true, opt = -1;
        MarkConfig_.key.main.forEach((item) => {
            if(!e[item]) flag = false;
        });

        if(flag){
            MarkConfig_.key.keyCode.map((item, index) => {
                if(e.keyCode == item || e.which == item || e.charCode == item) opt = index;
            })
        }
        return opt;
    }
    getSelected(){
        return window.getSelection ? window.getSelection(): document.selection.createRange().text;
    }
    deal(opt){
        let selecter = this.getSelected(),
            text = selecter.toString();

        if (text != '') {
          let rang = selecter.getRangeAt(0);
          let ele = document.createElement("lan");
          this.makeColor(ele, opt);
          ele.textContent = text;
          // console.log(ele);
          rang.surroundContents(ele);
        }
    }
    makeColor(ele, opt){
        ele.style.block = 'inline-block';
        ele.style.backgroundColor = MarkConfig_.color.backgroundColor[opt]?MarkConfig_.color.backgroundColor[opt]:MarkConfig_.color.backgroundColor[0];
        // ele.style.backgroundColor = '#e67e22';
        ele.style.color = '#fff';
    }


}

new MarkNowCoder_();
