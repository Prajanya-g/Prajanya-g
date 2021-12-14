
# include<iostream>

// the function prints the scales version of the array
// the function doesnt return any value
// the function has two parameter the 2d array and the scale

void print_scaled_matrix(int array[3][3],int scale){
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            array[row][col] = array[row][col] * scale;
            std::cout << array[row][col] << " ";
        }
        std::cout << std::endl;
    }
}
