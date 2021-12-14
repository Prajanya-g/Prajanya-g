 # include<iostream>
 
 int count(int array[], int n){
     int count = 0;
     for (int index = 0; index < n; index++){
         if(array[index]%2 == 0){
             count++;
         }
     }
     return count;
 }