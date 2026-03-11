#include "bmp.hpp"
#include <iostream>
#include <time.h>
#include <cmath>
color convert_to_grey(color c ){
    double y=0.299*c.r+0.114*c.b+0.587*c.g;
    int y_=std::round(y);
    if(y_>255)y_=255;
    if(y_<0)y_=0;
    return color{y_,y_,y_};
}

int main() {
    
    BMP bmp("sample.bmp"); 
     
    
    for(int i=0;i<bmp.get_width();i++){
        for(int j=0;j<bmp.get_height();j++){
                color o;
                bmp.get_pixel(i,j,o);                
                bmp.set_pixel(i,j,convert_to_grey(o));
        }

    }
    
     

    bmp.write("sample_grey_1.bmp"); // Save the image to a file

    return 0;
}