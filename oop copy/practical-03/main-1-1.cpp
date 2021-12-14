# include<iostream>
using namespace std;

extern void copy_2d_strings(string first[][2], string second[][2], int n);

int main(void){
    int length = 3;
    string first[3][2] = {{"ab","df"},{"bc","dsa"},{"cd","dsa"}};
    string second[length][2];
    copy_2d_strings(first,second,length);
    cout << second[2][2];
}
