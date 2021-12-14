# include<iostream>
# include<string>

extern void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents);

int main(void){
    std::string courses[4];
    std:: string students[4];
    int report_card[4][4];
    for(int row = 0; row < 4; row++){
        std::cin >> courses[row];
        std::cin >> students[row];
        for(int col = 0; col < 4; col++){
            std::cin >> report_card[row][col];
        }
    }
    print_class(courses,students,report_card,4);
    return 0;
}


