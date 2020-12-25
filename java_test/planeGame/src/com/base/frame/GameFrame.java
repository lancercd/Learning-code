package com.base.frame;

import com.base.element.BaseBom;
import com.element.Plane;
import com.element.Shell;
import com.util.ImageLoder;
import config.Config;


import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class GameFrame extends Frame {
    private Image bg_img;
    private Plane plane;
    private Shell[] shells;
    private BaseBom bom;

    private Image offScreenImage;

    private boolean is_over;



    public GameFrame(){
        this.init();
    }

    public GameFrame(int w, int h){
        this.init();
    }

    private void init(){
        Image plan_img = ImageLoder.getImage("images/plane.png");
        this.bg_img = ImageLoder.getImage("images/bg.png");
        this.is_over = false;
        this.offScreenImage = null;
        plane = new Plane(plan_img, (int)(Config.GAME_WIDTH / 2), Config.GAME_HEIGHT - Config.planeDefaultHeight - 10);
        this.shells = new Shell[50];

        for(int i=0; i<shells.length; ++i){
            this.shells[i] = new Shell();
        }
    }

    public void launchFrame()
    {

        this.setTitle("planeGame");
        this.setVisible(true);
        this.setSize(Config.GAME_WIDTH, Config.GAME_HEIGHT);
        this.setLocation(400, 100);
        this.setBackground(Color.white);

        this.addWindowListener(new WindowAdapter()
        {
            @Override
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });

        new PaintThread().start();
        addKeyListener(new KeyMonitor());


    }

    @Override
    public void paint(Graphics pen)
    {
        super.paint(pen);
        pen.drawImage(this.bg_img, 0, 0, Config.GAME_WIDTH, Config.GAME_HEIGHT, null);

        plane.drawSelf(pen);

        for(int i=0; i<this.shells.length; ++i){
            shells[i].draw(pen);
            boolean bom = shells[i].getRect().intersects(plane.getRect());
            if(bom) this.gameOver(pen);
        }
//        if(!this.is_over){
//
//        }
    }


    /**
     * 解决闪动问题 双缓冲
     * @param pen Graphics
     */
    public void update(Graphics pen){
//        super.update(pen);
        if(offScreenImage == null){
            offScreenImage = this.createImage(Config.GAME_WIDTH, Config.GAME_HEIGHT);
        }
        Graphics gOff = offScreenImage.getGraphics();
        paint(gOff);
        pen.drawImage(offScreenImage, 0, 0, null);

    }


    private void gameOver(Graphics pen){
        plane.death();
        this.is_over = true;
        if(this.bom == null){
            this.bom = new BaseBom(plane.getX(), plane.getY());
        }
        bom.draw(pen);
        if(bom.is_finish) plane.fadeout();
        System.out.println("bom");
    }




    class PaintThread extends Thread {

        @Override
        public void run()
        {
            while(true)
            {
                repaint();
                try {
                    Thread.sleep(40);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    class KeyMonitor extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e) {
//            super.keyPressed(e);
            plane.addDirection(e);
        }

        @Override
        public void keyReleased(KeyEvent e) {
//            super.keyReleased(e);
            plane.cancleDirection(e);
        }
    }





}
