# include<iostream>

int* sparse_count(int **vals,int num_rows, int num_cols){
    int *result = new int[2];
    result[0] = 0;
    result[1] = 0;
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            if(vals[row][col] == 0){
                result[0]++;
            }
            else{
                result[1]++;
            }
        }
    }
    return result;
}

