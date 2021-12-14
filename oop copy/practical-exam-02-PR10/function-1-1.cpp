#include<iostream>

int* create_ints(int num_vals){
    int* array = new int[num_vals];
    for (int index = 0; index < num_vals; index++) {
        array[index] = 5 * index;
    }
    return array;
}

void display_array(int *vals, int num_vals){
    for (int index = 0; index < num_vals; index++) {
        std::cout << vals[index] << " ";
    }
    std::cout << std::endl;
}
