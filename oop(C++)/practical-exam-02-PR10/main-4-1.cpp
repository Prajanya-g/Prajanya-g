# include<iostream>

extern int* sparse_count(int **vals,int num_rows, int num_cols);

int main(void){
    int row1[]={10,15,0};
    int row2[]={0,5,73};
    int row3[]={0,0,1};
    int *vals[]={row1,row2,row3};
    int nrows=3;
    int ncols=3;
    int *mm = sparse_count(vals,nrows,ncols);
    std::cout << mm[0] << " "<< mm[1] <<std::endl;
    return 0;
}

