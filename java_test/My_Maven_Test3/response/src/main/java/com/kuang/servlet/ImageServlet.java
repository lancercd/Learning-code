package com.kuang.servlet;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Random;

public class ImageServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        resp.setHeader("refresh", "10");
        //resp.getWriter().print("ok");

        BufferedImage image = new BufferedImage(80, 20, BufferedImage.TYPE_INT_RGB);

        Graphics2D g = (Graphics2D)image.getGraphics();

        g.setColor(Color.WHITE);
        g.fillRect(0, 0, 80, 20);

        g.setColor(Color.cyan);
        g.setFont(new Font(null, Font.BOLD, 20));

        String num = makeNum();
        g.drawString(num, 0, 20);
        System.out.println(num);
        resp.setContentType("image/jpeg");
        resp.setDateHeader("expires", -1);
        resp.setHeader("Cache-Control", "no-cache");
        resp.setHeader("Pragma", "no-cache");
        ImageIO.write(image, "jpeg", resp.getOutputStream());
    }


    private String makeNum(){
        Random random  = new Random();
        String num = String.valueOf(random.nextInt(999999));

        StringBuilder sb = new StringBuilder();
        for(int i=0; i< 7 - num.length(); ++i){
            sb.append("0");
        }
        String s = sb.toString() + num;
        return num;
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
