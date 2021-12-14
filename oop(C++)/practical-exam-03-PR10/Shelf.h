#ifndef SHELF_H
#define SHELF_H
#include"Lightbox.h"
#include<iostream>

class Shelf{
public:
    Shelf();
    Shelf(int width);
    int get_width();
    int get_number_of_lightboxes();
    Lightbox *get_contents();
    bool add_lightbox(Lightbox a_lightbox);
    int get_currentLength();
    int get_count();
    ~Shelf();

protected:
    int shelfSize;
    Lightbox *lightbox;
    int count;
    int currentLength;
};
#endif
