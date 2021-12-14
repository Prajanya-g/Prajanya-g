# include<iostream>

extern int binary_to_number(int binary_digits[], int number_of_digits);

int main(void){
    int binary[14] = {1,0,0,1,0,1,0,1,0,1,1,1,1,1};
    std::cout << "the number: " << binary_to_number(binary, 14) << std::endl;
}





