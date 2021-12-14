numberCourse = input("How many courses do you want to enrol in? ");
current_courses = [];
course = strings(numberCourse);
check = [numberCourse];
count = 1;
for index = 1:numberCourse
    fprintf("course %d", index);
    word = input(" ", 's');
    valid = valid_enrolment(current_courses, word);
    if(valid == true)
        fprintf("Enrolled\n");
        course(index) = word;
    else
        fprintf("Invalid Enrolment!\n");
        
    end
    current_couses(count) = word;
    count = count + 1;
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