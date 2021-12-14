#ifndef MEERKAT_H
#define MEERKAT_H
#include<string>
#include<iostream>

class meerkat
{
public:
    meerkat() ;
    void setName(std::string meerName);
    std::string getName();
    void setAge(int meerAge);        
    int getAge();
    ~meerkat();
    
protected:
    std::string name;
    int age;
};
#endif
