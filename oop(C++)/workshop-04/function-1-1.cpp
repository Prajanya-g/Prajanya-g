# include<iostream>

int size(){
    int a = 5;
    int *t = new int;
    t = &a;
    return sizeof(t);
}
