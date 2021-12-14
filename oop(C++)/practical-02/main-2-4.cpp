# include<iostream>

extern int sum_min_and_max(int integers[], int length);
extern int max_integer(int integers[], int length);
extern int min_integer(int integers[], int length);

int main(void){
    int intergers[6] = {1,3,8,4,9};
    std::cout << "the max: " << sum_min_and_max(intergers, 5) << std::endl;
}




