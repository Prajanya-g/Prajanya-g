numberCourse = input("How many courses do you want to enrol in? ");
course = strings(numberCourse);
check = [numberCourse];
for index = 1:numberCourse
    fprintf("course %d", index);
    word = input(" ", 's');
    course(index) = word;
    if(course(index) == "ENG 1002" || course(index) == "ENG 1003")
        check(index) = 1;
    else
        check(index) = 0;
    end
end

fprintf("The courses you enrolled in are:\n")
for i = 1: numberCourse
    fprintf("course %d: ", i)
    if(check(i) == 1)
        fprintf("programming\n");
    else
        fprintf("not programming\n");
    end
end