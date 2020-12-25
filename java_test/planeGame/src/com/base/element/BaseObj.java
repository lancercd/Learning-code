package com.base.element;

import config.Config;

import java.awt.*;

public abstract class BaseObj {
    protected Image  img;
    protected int    x,y;
    protected int    speed;
    protected int    width, height;

    protected boolean is_left, is_right, is_up, is_down;

    public BaseObj(){}

    protected BaseObj(Image img, int x, int y){
        super();
        this.speed = 5;
        this.img = img;
        this.x = x;
        this.y = y;
    }

    protected BaseObj(Image img, int x, int y, int speed, int width, int height){
        super();
        this.img = img;
        this.x = x;
        this.y = y;
        this.speed = speed;
        this.width = width;
        this.height = height;
    }

    public void drawSelf(Graphics pen){
        pen.drawImage(this.img, this.x, this.y, null);
    }

    public Rectangle getRect(){
        return new Rectangle(this.x, this.y, this.width, this.height);
    }



    protected abstract void move();
}
