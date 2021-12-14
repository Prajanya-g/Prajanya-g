# include<iostream>

int *readNumbers(){
    int length = 10;
    int* numbers = new int[length];
    for(int i = 0; i < length; i++){
        std::cout<< "Please enter the number " << i << " ";
        std::cin >> *(numbers+i);
    }
    return numbers;
}

int secondSmallestSum(int *numbers,int length){
    int max = *numbers;
    int second = *numbers+1;
    for (int i = 0; i < length; i++) {
        int temp = 0;
        for (int j = i ; j < length; j++) {
            temp += numbers[j];
            std::cout<< "sum of " << j << " "<< i << " " <<temp << std::endl;
            if(temp > max){
                if(second <= max){
                    second = max;
                }
                max = temp;
            }
            if(second < temp && temp != max ){
                second = temp;
            }
        }
    }
    return second;
}
