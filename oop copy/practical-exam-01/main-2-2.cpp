# include<iostream>

extern int binary_to_number(int binary_digits[], int number_of_digits);

int main(void){
    int binary[12] = {1,1,0,1,0,1,1,0,0,1,0,1};
    std::cout << " The number is: " << binary_to_number(binary, 12)<< std::endl;
    return 0;
}
