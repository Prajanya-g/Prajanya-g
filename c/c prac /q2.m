numberCourse = input("how many course do you want to enrol in?");
courses = strings(numberCourse);
check = 0;
for i = 1 : numberCourse
    fprintf("Course %d", i);
    word = input(" ",'s');
    courses(i) = word;
    if(courses(i) == "ENG 1002" || courses(i) == "ENG 1003")
        check = 1;
    end
end

if(check == 0)
    fprintf("not enrolled");
else
    fprintf("Awesome! You are enrolled in programming.");
end