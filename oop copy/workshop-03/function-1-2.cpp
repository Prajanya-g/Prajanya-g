# include<iostream>
# include<string>

void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents){
    std::cout<< "Report Card ";
    for (int i = 0 ; i < nstudents-1; i++) {
        std::cout<< courses[i]<< " ";
    }
    std::cout<< courses[nstudents-1]<< std::endl;
    
    for(int row = 0; row < nstudents; row++){
        std::cout << students[row]<< " ";
        for(int col = 0; col < nstudents-1; col++){
            std::cout << report_card[row][col] << " ";
        }
        std::cout << report_card[row][nstudents-1] << std::endl;
    }
}
