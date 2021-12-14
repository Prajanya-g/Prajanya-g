# include<iostream>

// the checks if the matrix is an indentity matrix
// the function return 1 or 0 based on the check
// the function has one parameter the matrix

int identity(int array[10][10]){
    int check = 0;
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 10; col++){
            if(col == row){
                if(array[row][col] == 1){
                    check = 1;
                }
                else{
                    check = 0;
                    return check;
                }
            }
            else{
                if(array[row][col] == 0){
                    check = 1;
                }
                else{
                    check = 0;
                    return check;
                }
            }
        }
    }
    return check;
}
