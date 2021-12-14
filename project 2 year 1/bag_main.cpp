#include <iostream>
#include "Item.h"
#include "Bag.h"
using namespace std;

int main()
{
    //creating a bag
    Bag bagpack;
    // creating item
    Item item1,item2;
    item1.setName("coin");
    item2.setName("sword");
    // adding both items and droping them
    bagpack.pick(item1);
    bagpack.pick(item1);
    bagpack.display();
    std::cout <<"should return 1" <<bagpack.checkItem(item1) << std::endl;
    bagpack.display();
    return 0;
}

