# include<iostream>

extern int sum_if_a_palindrome(int integers[], int length);
extern bool is_a_palindrome(int integers[], int length);
extern int sum_elements(int integers[], int length);


int main(void){
    int sequence[9] = {1,0,4,0,1,0,4,0,1};
    std::cout << " The number is: " << sum_if_a_palindrome(sequence,9)<< std::endl;
    return 0;
}

