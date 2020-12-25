package com.util;


import javax.imageio.ImageIO;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;

public class ImageLoder {
    private ImageLoder(){}

    public static Image getImage(String path){
        BufferedImage bi = null;
        try{
            URL url = ImageLoder.class.getClassLoader().getResource(path);
            bi = ImageIO.read(url);
        }catch (IOException e){
            e.printStackTrace();
        }
        return bi;
    }
}
