numberCourse = input("How many courses do you want to enrol in? ");
current_courses = strings(numberCourse);
course = strings(numberCourse);
check = [numberCourse];
index = 1;
count = 1;
while (index ~= numberCourse+1)
    fprintf("course %d", index);
    word = input(" ", 's');
    valid = valid_enrolment(current_courses, word);
    if(valid == true)
        fprintf("Enrolled\n");
        course(index) = word;
        current_courses = course;
    if(course(index) == "ENG 1002" || course(index) == "ENG 1003")
        check(index) = 1;
    else
        check(index) = 0;
    end
            index = index + 1;
    else
        fprintf("Invalid Enrolment!\n");
    end
end
fprintf("The courses you enrolled in are:\n")
for i = 1: numberCourse
    fprintf("course %d: ", i)
    if(check(i) == 1)
        fprintf("%s programming\n", course(index));
    else
        fprintf("%s not programming\n", course(index));
    end
end
