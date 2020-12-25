package com.element;

import com.base.element.BaseObj;
import config.Config;

import java.awt.*;
import java.awt.event.KeyEvent;


public class Plane extends BaseObj {

    private boolean is_live;

    public Plane() {this.is_live = true;}

    public Plane(Image img, int x, int y) {
        super(img, x, y, Config.planeDefaultSpeed, Config.planeDefaultWidth - 5, Config.planeDefaultHeight - 5);
        this.is_live = true;
    }

    @Override
    public void drawSelf(Graphics pen) {
        if(this.is_live){
            //pen.drawImage(this.img, this.x, this.y, null);
            pen.drawImage(this.img, this.x, this.y, Config.planeDefaultWidth, Config.planeDefaultHeight, null);
            this.move();
        }
    }

    public void addDirection(KeyEvent e){
        switch(e.getKeyCode()){
            case 37:
                this.is_left = true;
                break;
            case 38:
                this.is_up = true;
                break;
            case 39:
                this.is_right = true;
                break;
            case 40:
                this.is_down = true;
                break;
        }
    }

    public void cancleDirection(KeyEvent e){
        switch(e.getKeyCode()){
            case 37:
                this.is_left = false;
                break;
            case 38:
                this.is_up = false;
                break;
            case 39:
                this.is_right = false;
                break;
            case 40:
                this.is_down = false;
                break;
        }
    }

    protected void move(){
        if(this.is_left){this.x -= this.speed;}
        if(this.is_up){this.y -= this.speed;}
        if(this.is_right){this.x += this.speed;}
        if(this.is_down){this.y += this.speed;}
    }


    public void death(){
        this.is_live = false;
//        this.height = 0;
//        this.width = 0;
    }

    public void fadeout(){
        this.height = 0;
        this.width = 0;
    }

    public int getX(){
        return this.x;
    }
    public int getY(){
        return this.y;
    }
}
