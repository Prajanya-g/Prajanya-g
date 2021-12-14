#ifndef COMPUTER_H
#define COMPUTER_H

class computer{
public:
    computer();
    computer(string letter);
    virtual void move();
    virtual string getMoves();
    ~computer();
protected:

};
#endif

