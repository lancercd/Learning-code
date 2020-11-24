package com.kuang.servlet;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URLEncoder;

public class FileServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        String realPath = this.getServletContext().getRealPath("/1.png");
        String realPath = "D:\\study\\java\\idea_work_place\\My_Maven_Test3\\response\\src\\main\\resources\\很好.png";
        System.out.println("realPath");

        String fileName = realPath.substring(realPath.lastIndexOf("\\") + 1);

        resp.setHeader("Content-Disposition", "attachment;filename=" + URLEncoder.encode(fileName, "UTF-8"));

        FileInputStream in = new FileInputStream(realPath);
        int len = 0;
        byte[] buffer = new byte[1024];

        ServletOutputStream out = resp.getOutputStream();
        while((len = in.read(buffer)) != -1){
            out.write(buffer, 0, len);
        }
        in.close();
        out.close();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
