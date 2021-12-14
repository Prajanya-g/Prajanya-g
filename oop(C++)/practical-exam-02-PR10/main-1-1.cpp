# include<iostream>

extern int* create_ints(int num_vals);
extern void display_array(int *vals, int num_vals);

int main(void){
    int *array = create_ints(10);
    display_array(array,10);
    delete[] array;
    return 0;
}
