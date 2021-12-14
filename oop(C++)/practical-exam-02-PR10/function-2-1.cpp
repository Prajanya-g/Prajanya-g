# include<iostream>
# include<string>
using namespace std;

string lookup_spectrum(int day){
    switch (day) {
        case 1:
            return "Red";
        case 2:
            return "Orange";
        case 3:
            return "Yellow";
        case 4:
            return "Green";
        case 5:
            return "Blue";
        case 6:
            return "Indigo";
        case 7:
            return "Violet";
        default:
            return "invalid colour";
    }
}
