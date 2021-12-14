#ifndef CART_H
#define CART_H
#include<string>
#include"meerkat.h"

class cart : public meerkat{
public:
    cart();
    bool addMeerkat(meerkat cat);
    void emptyCart();
    void printMeerkats();
    ~cart();
    
private:
    int passenger;
    meerkat meerkatCart[4];
};
#endif
