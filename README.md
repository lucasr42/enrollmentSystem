# enrollmentSystem
Design and implement a basic university enrollment system
-----------------
    READ ME
-----------------

Authors:

Lucas Robinson
Ishmaeel Daud

Design:

Lucas Robinson
Ishmaeel Daud
Nam Nguyen
Jamin Debu

This is a class assignment from CSS 342 Data Structures & Algorithms 1. The 
requirements were to design and implement a university enrollment system. All 
code in the following files was produced by myself and the teammates noted 
above:
- enrollmentsystem.cpp
- university.h
- univserity.cpp
- student.h
- student.cpp
- course.h
- course.cpp
All other code was provided with the assignment. It can be ran by using the script 
./runit.sh

This program mimics a university enrollment system. It allows adding and 
removing of schools from the overall university system. It can also enroll, add, and 
remove courses to and from those universities, and adding and removing 
students to both the university and the courses.

-----------------
CLANG-TIDY ERRORS
-----------------

1. course.cpp:16:16: error: 2 adjacent parameters of 'Course' of similar type
    Course::Course(const string &cID, const string &name)

    - Two different string that represent two different variables, structure is
     unavoidable.

2. student.cpp:16:27: error: 2 adjacent parameters of 'Student' of similar type
    Student::Student(int sID, const string &lastName, const string &firstName)

    - Two string types are in the parameter meaning two different things, 
    however it makes more sense for them to be next to one another than 
    separated.

3. enrollmentsystem.cpp:75:8: error: implicit conversion 'std::ifstream' 
    (aka 'int') -> bool
    - Implicit conversion is expected behavior here.

4. wchar.h:35:10: error: 'stddef.h' file not found 
    - We can't do anything about this clang tidy error, has appeared in the 
    last couple of projects as well.
