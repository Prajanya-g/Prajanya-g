# include<iostream>
using namespace std;

void copy_2d_strings(string first[][2], string second[][2], int n){
    for (int row = 0; row < n ; row++) {
        for(int col = 0; col < 2; col++){
            second[row][col] = first[row][col];
        }
    }
}
