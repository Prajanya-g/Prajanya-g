#ifndef ORCHESTRA_H
#define ORCHESTRA_H
#include"Musician.h"

class Orchestra{
public:
    Orchestra();
    Orchestra(int size);
    int get_current_number_of_members();
    bool has_instrument(std::string instrument);
    Musician *get_members();
    bool add_musician(Musician new_musician);
    ~Orchestra();
protected:
    int size;
    Musician *musician;
    int count;
};
#endif

