package com.kuang.request;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.Writer;
import java.util.Arrays;

public class Login extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        resp.setContentType("text/html");
        resp.setContentType("charset=UTF-8");


        String username = req.getParameter("username");
        System.out.println(req.getParameter("username"));
        String pwd = req.getParameter("pwd");
        System.out.println(req.getParameter("pwd"));
        String[] boxs = req.getParameterValues("boxs");
        Writer writer = resp.getWriter();
        writer.write("username " + username + "   pwd:" + pwd + "<br>");
        writer.write(Arrays.toString(boxs));
        System.out.println(Arrays.toString(boxs));

        //req.getRequestDispatcher("/success.jsp").forward(req, resp);
//        for (int i = 0; i < boxs.length; ++i) {
//            writer.write(boxs[i]);
//        }
    }
}
