package com.kuang.servelt;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class GetServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        ServletContext context = this.getServletContext();

        resp.setCharacterEncoding("utf-8");
//        resp.setHeader("Content-Type", "text/html");
        resp.setContentType("text/html");
        String username = (String) context.getAttribute("username");

        resp.getWriter().print(username);
    }
}
