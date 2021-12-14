# include<iostream>

void printer(int array[10][10]){
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 9 ; col++) {
            std::cout << array[row][col] << " ";
        }
        std::cout<< array[row][9] << std::endl;
    }
}
