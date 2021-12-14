# include<iostream>
# include<string>

extern void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents);

int main(void){
    std::string courses[4] = {"MATHS","SCIENCE","ENGLISH","ECONOMICS"};
    std:: string students[4] ={"a","b","c","d"};
    int report_card[4][4] = {{1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
    };
    print_class(courses,students,report_card,4);
    return 0;
}

