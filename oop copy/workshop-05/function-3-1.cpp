# include<iostream>

int *readNumbers(){
    int length = 10;
    int* numbers = new int[length];
    for(int i = 0; i < length; i++){
        std::cout<< "Please enter the number" << i;
        std::cin >> *(numbers+i);
    }
    return numbers;
}

bool equalsArray(int *numbers1,int *numbers2,int length){
    for(int i = 0; i < length; i++){
        if(numbers1[i] == numbers2[i]){
            return false;
        }
    }
    return true ;
}
