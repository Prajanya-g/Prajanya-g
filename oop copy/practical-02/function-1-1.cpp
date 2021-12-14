# include<iostream>

// the function calcualtes hte sum of the diagonal
// the function return the sum
// there is one parmeter the 2d array
int diagonal(int array[4][4]){
    int sum = 0;
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(col == row){
                sum += array[row][col];
            }
        }
    }
    return sum;
}
