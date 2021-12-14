# include<iostream>

// the function covert the decimal number to interger and then to binary
// there is not return value
// there is one parameter the string
void print_as_binary(std::string decimal_number){
    int binary[32];
    int number = stoi(decimal_number);
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
}
