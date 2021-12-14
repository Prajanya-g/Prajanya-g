# include<iostream>

// the function counts the number of 0-9
// the function doesnt return any value
// the function has one parameter a 2d array

void count_numbers(int array[4][4]){
    int count[10]={0,0,0,0,0,0,0,0,0,0};
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(array[row][col] == 0){
                count[0]++;
            }
            else if(array[row][col] == 1){
                count[1]++;
            }
            else if(array[row][col] == 2){
                count[2]++;
            }
            else if(array[row][col] == 3){
                count[3]++;
            }
            else if(array[row][col] == 4){
                count[4]++;
            }
            else if(array[row][col] == 5){
                count[5]++;
            }
            else if(array[row][col] == 6){
                count[6]++;
            }
            else if(array[row][col] == 7){
                count[7]++;
            }
            else if(array[row][col] == 8){
                count[8]++;
            }
            else if(array[row][col] == 9){
                count[9]++;
            }
        }
    }
        std::cout << "0:" << count[0] << ";1:" << count[1]<< ";2:" << count[2]<< ";3:" << count[3]<< ";4:" << count[4]<< ";5:" << count[5]<< ";6:" << count[6]<< ";7:" << count[7]<< ";8:" << count[8]<< ";9:" << count[9] <<";"<<std::endl;
}
