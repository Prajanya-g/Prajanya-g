# include<iostream>

extern int sum_if_a_palindrome(int integers[], int length);
extern bool is_a_palindrome(int integers[], int length);
extern int sum_elements(int integers[], int length);

int main(void){
    int intergers[6] = {1,1,0,1,1};
    std::cout << "the number: " << sum_if_a_palindrome(intergers, 5) << std::endl;
}






