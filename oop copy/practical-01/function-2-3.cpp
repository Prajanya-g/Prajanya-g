# include<iostream>

// the function counts the number of 2s 5s and 9s in the given array
// the function doesnt return any value
// there are two parameter the array and its length

void twofivenine(int array[], int n){
    // declaring variable for 2s 5s and 9s
    int two = 0;
    int five = 0;
    int nine = 0;
    // using for loop to iterate throught eeach value
    for(int index = 0; index < n; index++){
        if(array[index] == 2){
            two++;
        }
        else if(array[index] == 5){
            five++;
        }
        else if(array[index] == 9){
            nine++;
        }
    }
    if(n<1){
        std::cout<<"there are no values in the array"<<std::endl;
    }
    else{
    std::cout<<"2:"<<two<<";5:"<<five<<";9:"<<nine<<";"<<std::endl;
    }
}
