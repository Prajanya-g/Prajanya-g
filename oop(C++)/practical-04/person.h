#ifndef PERSON_H
#define PERSON_H
#include<string>

class person
{
public:
    person();
    person(std::string myName,int Salary);
    void setName(std::string myName);
    std::string getName();
    void setSalary(int mySalary);
    int getSalary();
    ~person();
    
protected:
    std::string name;
    int salary;
};
#endif
