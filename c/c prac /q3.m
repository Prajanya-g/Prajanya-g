numberCourse = input("how many course do you want to enrol in?");
courses = strings(numberCourse);
check = [];
for i = 1 : numberCourse
    fprintf("Course %d", i);
    word = input(" ",'s');
    courses(i) = word;
    if(courses(i) == "ENG 1002" || courses(i) == "ENG 1003")
        check(i) = 1;
    else
        check(i) = 0;
    end
end

for i = 1 : numberCourse
    fprintf("%s", courses(i))
    if(check(i) == 1)
        fprintf("Programming");
    else
        fprintf("not programming");
    end
end