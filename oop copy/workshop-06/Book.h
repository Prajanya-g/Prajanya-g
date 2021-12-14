# ifndef BOOK_H
# define BOOK_H

#include <string>

class book
{
public:
    book();
    book(std::string argname, int argcopies);
    std::string name;
    int copies;
    int pid;
    static int nextid;
    void borrow();
    void returnBook();
    ~book();
};
#endif
