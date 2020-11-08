<%@ page import="com.Persion" %>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>lancercd</title>
    </head>
<body>
    Hello World!<br/>
    <%
        out.println("你的 IP 地址 " + request.getRemoteAddr());
        Persion per = new Persion();

        out.println(per.getInfo());
        // System.out.println(per.getInfo());
    %>
</body>
</html>
