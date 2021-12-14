numberCourse = input("How many courses do you want to enrol in? ");
current_courses = ["ENG 1002"; "MATHS 1" ;"PHYSICS 2"];
course = strings(numberCourse);
check = [numberCourse];
for index = 1:numberCourse
    fprintf("course %d", index);
    word = input(" ", 's');
    course(index) = word;
    valid = valid_enrolment(current_courses, course(index));
    if(valid == true)
        fprintf("Can Enrol\n");
    else
        fprintf("Invalid Enrolment!\n");
    end
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