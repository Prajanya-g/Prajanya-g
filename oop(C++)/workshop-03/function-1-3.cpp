# include<iostream>
# include<string>

void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents){
    std::cout<< "name";
    for (int i = 0 ; i < nstudents; i++) {
        std::cout<< courses[i];
    }
    std::cout << std::endl;
    for(int row = 0; row < nstudents; row++){
        std::cout << students[row];
        for(int col = 0; col < nstudents; col++){
            std::cout << report_card[row][col];
        }
        std::cout << std::endl;
    }
}

