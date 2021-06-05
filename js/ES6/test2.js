function optionTest(option) {
    const defaultOption = {
        url: 'https://lancercd.top/upload',
        size: 10240,
        type: '*.jpeg,*.png'
    };

    /* 后面的选项 会将前面的覆盖 */

    //使用展开语法
    const finalOption = { ...defaultOption, ...option };

    //使用Object.assign
    const finalOption2 = Object.assign(defaultOption, option);

    console.log(finalOption);   //{ url: 'https://lancercd.top/upload', size: 999, type: '*.gif' }
    console.log(finalOption2);  //{ url: 'https://lancercd.top/upload', size: 999, type: '*.gif' }
}

optionTest({
    size: 999,
    type: '*.gif'
})