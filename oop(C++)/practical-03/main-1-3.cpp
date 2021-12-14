# include<iostream>

extern void cpyia(int old_array[],int new_array[],int length);

int main(void){
    int l = 3;
    int first[] = {1,2,3};
    int second[l];
    cpyia(first,second,l);
    for (int i = 0; i<l; i++) {
        std::cout<< second[i]<< " ";
    }
}
