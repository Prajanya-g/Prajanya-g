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

void printNumbers(int *numbers,int length){
    for(int i = 0; i < length; i++){
        std::cout << i <<" " <<*(numbers+i) << std::endl;
    }
    delete[] numbers;
}
