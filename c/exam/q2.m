numberCourse = input("How many courses do you want to enrol in? ");
course = strings(numberCourse);
check = 0;
for index = 1:numberCourse
    fprintf("course %d", index);
    word = input(" ", 's');
    course(index) = word;
    if(course(index) == "ENG 1002" || course(index) == "ENG 1003")
        check = 1;
    end
end
 
if(check == 1)
    fprintf("Awesome! You are enrolled in programming.");
else
    fprintf("Awwww, no programming for you.");
end
