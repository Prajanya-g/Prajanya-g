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

int *reverseArray(int *numbers1,int length){
    int* newnumber = new int[length];
    for(int i = 0; i < length; i++){
        newnumber[i] = numbers1[length-i];
    }
    return newnumber;
}


void printNumbers(int *numbers,int length){
    for(int i = 0; i < length; i++){
        std::cout << i <<" " <<*(numbers+i) << std::endl;
    }
    delete[] numbers;
}


