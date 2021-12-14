# include<iostream>

int main(void){
    int binary[32];
    int number = 73;
    int count = 0;
    while(number != 1){
        if(number%2 == 1){
            binary[count] = 1;
        }
        else{
            binary[count] = 0;
        }
        number = number/2;
        count++;
    }
    binary[count] = 1;
    for(int i = count; i >= 0; i = i -1){
        std::cout << binary[i];
    }
    std::cout << std::endl;
    return 0;
}
