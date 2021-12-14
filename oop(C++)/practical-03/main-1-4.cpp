
# include<iostream>

extern void cpyda(double *old_array,double *new_array,int length) ;

int main(void){
    int l = 3;
    double first[] = {1,2,3};
    double second[l];
    cpyda(&first[0],&second[0],l);
    for (int i = 0; i<l; i++) {
        std::cout<< second[i]<< " ";
    }
}
