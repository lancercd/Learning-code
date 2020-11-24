package com.filter;

import javax.servlet.*;
import java.io.IOException;

public class FilterTest implements Filter {
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        response.setContentType("text/html;charset=UTF-8");


        chain.doFilter(request, response);
    }

    public void init(FilterConfig filterConfig) throws ServletException {
        System.out.println("-----调用init方法");
    }

    public void destroy() {
        System.out.println("-----调用destroy");
    }
}
