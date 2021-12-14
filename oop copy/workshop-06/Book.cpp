#include <iostream>
#include "book.h"

using namespace std;

int book::nextid = 111;

book::book()
{
    name = "?";
    copies = 0;
    pid = nextid;
    nextid++;
}


book::book(std::string argname, int argcopies)
{
    name = argname;
    copies = argcopies;
    pid = nextid;
    nextid++;
}

// implementation of the Panda treat function
void book::borrow()
{
    if(copies < 1){
        cout<<"there are no copies available"<<endl;
    }
    else{
    cout<<"you borrowed: "<< name  <<" "<< pid <<endl;
        copies--;
    }
}
void book::returnBook(){
    cout<< "you returned the book: "<< name<< " " << pid<<endl;
    copies++;
}

// implementation of the default Panda destructor
book::~book()
{
}

