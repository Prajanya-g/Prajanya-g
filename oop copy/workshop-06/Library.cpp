#include <iostream>
#include "book.h"

using namespace std;


int main()
{
    book *a, *b, *c;
    a = new book("a",1);
    b = new book("b",2);
    c = new book("c",2);
    a->borrow();
    b->returnBook();
    c->borrow();
}
