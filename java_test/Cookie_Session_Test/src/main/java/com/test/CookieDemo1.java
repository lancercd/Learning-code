package com.test;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

public class CookieDemo1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        resp.setContentType("text/html;charset=UTF-8");
        //resp.setHeader("content-type", "text/html;charset=UTF-8");

        PrintWriter out = resp.getWriter();

        //getCookies 返回Cookies[]    说明Cookie可能有多个
        Cookie[] cookies = req.getCookies();

        for(Cookie coo : cookies){
            print(coo.getName() + " : " + coo.getValue());
            out.println(coo.getName() + " : " + coo.getValue());
        }


//        if(cookies != null){
//            Cookie coo = new Cookie("times", "2");
//            resp.addCookie(coo);
//            String times = "", lastTime = "";
//            out.write("宁上一次访问的时间是:");
//
//            for(Cookie cookie : cookies){
//                if(cookie.getName().equals("times")){
//                    times = cookie.getValue();
//                    print(times);
//                }
//                if(cookie.getName().equals("lastLoginTime")){
//                    lastTime = cookie.getValue();
//                    print(lastTime);
//                }
//            }
//            out.write(new Date(lastTime).toLocaleString());
//            out.write(times);
//
//
//        }else{
//            out.write("这是宁第一次访问");
//
//            Cookie coo = new Cookie("times", "1");
//            resp.addCookie(coo);
//
//        }

        Cookie cooLastTime = new Cookie("lastLoginTime", System.currentTimeMillis() + "");
        Cookie cooTime = new Cookie("times", "1");
        cooTime.setMaxAge(24 * 60 * 60);
        resp.addCookie(cooLastTime);
        resp.addCookie(cooTime);


    }

    private void print(String str){
        System.out.println(str);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}
