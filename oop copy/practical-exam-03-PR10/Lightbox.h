#ifndef LIGHTBOX_H
#define LIGHTBOX_H
#include<iostream>

class Lightbox{
public:
    Lightbox();
    Lightbox(std::string colourname, int width);
    std::string get_colour();
    int get_width();
    ~Lightbox();
protected:
    std::string color;
    int size;
};
#endif
