<%--
  Created by IntelliJ IDEA.
  User: comfort
  Date: 2020/11/23
  Time: 17:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>hellp</title>
</head>
<body>
hello world WEB

<form action="${pageContext.request.contextPath}/login" method="post">
    用户名: <input type="text" name="username"></br>
    密码 : <input type="pwd" name="pwd"></br>

    <input type="checkbox" name="boxs" value="1">1
    <input type="checkbox" name="boxs" value="2">2
    <input type="checkbox" name="boxs" value="3">3
    <input type="submit">
</form>
</body>
</html>
