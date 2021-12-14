# include<iostream>

void odd_even(int vals[], int exmpl, int length){
    if(exmpl == 0){
        for (int index = 0; index < length; index++) {
            std::cout << index<<":"<<vals[index]<<" ";
        }
        std::cout<<std::endl;
    }
    else if((exmpl%2 == 1)){
        for (int index = 0; index < length; index++) {
            if(vals[index]%2 == 1){
                std::cout << index<<":"<<vals[index]<<" ";
            }
        }
        std::cout<<std::endl;
    }
    else{
        for (int index = 0; index < length; index++) {
            if(vals[index]%2 == 0){
                std::cout << index<<":"<<vals[index]<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

