#include<string>
#include<iostream>
#include"Lightbox.h"
#include"Shelf.h"

Shelf::Shelf(){
    shelfSize = 0;
    count = 0;
    currentLength =0;
}
Shelf::Shelf(int width){
    shelfSize = width;
    lightbox = new Lightbox[shelfSize];
    count = 0;
    currentLength = 0;
}

int Shelf::get_width(){
    return shelfSize;
}
int Shelf::get_number_of_lightboxes(){
    return count;
}
Lightbox* Shelf::get_contents(){
    return lightbox;
}
bool Shelf::add_lightbox(Lightbox a_lightbox){
    int newLength = currentLength + a_lightbox.get_width();
    if(newLength > shelfSize){
        return false;
    }
    lightbox[count] = a_lightbox;
    count++;
    currentLength = newLength;
    return true;
}
int Shelf::get_currentLength(){
    return currentLength;
}
int Shelf::get_count(){
    return count;
}
Shelf::~Shelf(){
    delete[] lightbox;
}
