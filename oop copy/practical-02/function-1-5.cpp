 
# include<iostream>

// the function prints the sum of two 2darray
// the function doesnt return any value
// the function has two parameter the 2d arrays

void print_summed_matrices(int array1[3][3],int array2[3][3]){
    int newArray[3][3];
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            newArray[row][col] = array1[row][col] + array2[row][col];
            std::cout << newArray[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

