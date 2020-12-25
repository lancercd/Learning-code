package com.base.element;

import com.util.ImageLoder;

import java.awt.*;

public class BaseBom {
    protected int x, y;
    private int count;
    public boolean is_finish;
    private static Image[] imgs;

    static{
        imgs = new Image[16];
        for(int i=0; i<16; ++i){
            imgs[i] = ImageLoder.getImage("images/bom/e" + (i + 1) + ".gif");
            imgs[i].getWidth(null);
        }
    }
    public BaseBom(){this.x = 0; this.y = 0;this.count = 0;this.is_finish = false;}

    public BaseBom(int x, int y){
        this.x = x;
        this.y = y;
        this.count = 0;
        this.is_finish = false;
    }

    public void draw(Graphics pen){
        if(this.count < 16){
            pen.drawImage(imgs[this.count], this.x, this.y, null);
            ++this.count;
        }
        if(this.count >= 16) this.is_finish = true;
    }

    public void dray(Graphics pen, int x, int y){
        if(this.count < 16){
            pen.drawImage(imgs[this.count], x, y, null);
            ++this.count;
        }

    }


}
