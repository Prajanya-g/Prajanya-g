# include<iostream>

int main(void){
    int x[2][3] = {{42,23,3},{12,32,52}};
    int (*y)[3] = x;
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++) {
            std::cout << *(*(y + i) + j);
           
        }
        std::cout << std::endl;
    }
      return 0;
}




