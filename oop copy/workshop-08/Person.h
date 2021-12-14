#ifndef PERSON_H
#define PERSON_H

class person{
public:
    person();
    virtual void move();
    virtual string getMoves();
    ~person();
protected:
    char *moves;
};
#endif

