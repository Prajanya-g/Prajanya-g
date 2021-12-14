#include<string>
#include<iostream>
#include"Lightbox.h"

Lightbox::Lightbox(){
    color = "null";
    size = 0;
}
Lightbox::Lightbox(std::string colourname, int width){
    color = colourname;
    size = width;
}
std::string Lightbox::get_colour(){
    return color;
}
int Lightbox::get_width(){
    return size;
}
Lightbox::~Lightbox(){
}
