#ifndef MUSICIAN_H
#define MUSICIAN_H

class Musician{
public:
    Musician();
    Musician(std::string instrument, int experience);
    std::string get_instrument();
    int get_experience();
    ~Musician();
protected:
    int years;
    std::string instrumentPlayed;
};
#endif
