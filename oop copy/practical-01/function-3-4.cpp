# include<iostream>

// the function uses switch to print pass or fail based on the grade
// there is one parameter grade

void passorfail(char grade){
    // using switch case
    switch (grade) {
        case 'A':
            std::cout << "Pass" << std::endl;
            break;
            
        case 'B':
            std::cout << "Pass" << std::endl;
            break;
            
        case 'C':
            std::cout << "Pass" << std::endl;
            break;
            
        case 'D':
            std::cout << "Fail" << std::endl;
            break;
            
        case 'E':
            std::cout << "Fail" << std::endl;
            break;
            
        default:
            break;
    }
}
