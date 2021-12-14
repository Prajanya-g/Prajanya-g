function valid = valid_enrolment(current_courses_array, new_course)
    for row = 1 : length(current_courses_array)
        if (current_courses_array(row,1) == new_course)
            valid = false;
            break;
        else
            valid = true;
        end
    end
end