# include<iostream>

extern int diagonal(int array[4][4]);

int main(void){
    int array[4][4] = {
        {1,2,3,4},
        {2,3,3,4},
        {4,5,6,7},
        {5,5,5,5},
    };
    std::cout << "the sum of the diagonals: " << diagonal(array) << std::endl;
}
