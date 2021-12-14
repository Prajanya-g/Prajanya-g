# include<iostream>

int size_of_array_arr(){
    int *arr = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3312;
    return sizeof(arr);
}
