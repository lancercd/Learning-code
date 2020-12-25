package com.element;

import com.base.element.BaseObj;
import config.Config;

import java.awt.*;

public class Shell extends BaseObj {
    protected double degree;

    public Shell(){
        this.x = (int)(Math.random() * Config.GAME_WIDTH);
        this.y = (int)(Math.random() * Config.GAME_WIDTH / 3);
        this.width = 10;
        this.height = 10;
        this.speed = Config.shellDefaultSpeed;

        this.degree = Math.random() * Math.PI * 2;
    }

    public void draw(Graphics pen){
        Color c = pen.getColor();
        pen.setColor(Color.YELLOW);
        pen.fillOval(this.x, this.y, this.width, this.height);

        move();

        pen.setColor(c);
    }


    protected void move(){
        this.x += (int)(this.speed * Math.cos(this.degree));
        this.y += (int)(this.speed * Math.sin(this.degree));

        rebound();
    }


    protected void rebound(){
        if(this.x < 0 || this.x > Config.GAME_WIDTH - this.width){
            this.degree = Math.PI - degree;
        }

        if(this.y < 30 || this.y > Config.GAME_HEIGHT - this.height){
            this.degree = - degree;
        }

    }
}
