#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Course;

class Student {
  friend class Course;
  friend class University;
  friend class EnrollmentSystem;

private:
  // student ID number
  int studentID;
  // students last name
  string studentLastName;
  // students first name
  string studentFirstName;
  // students schedule
  map<string, Course *> studentSchedule;

public:
  // initialized constructor
  explicit Student(int sID, const string &lastName, const string &firstName);

  // copy constructor
  Student(const Student &other) = delete;

  // move constructor
  Student(const Student &&other) = delete;

  // assignment operator
  Student &operator=(const Student &stud) = delete;

  // move operator
  Student &operator=(const Student &&stud) = delete;

  // destructor
  ~Student() = default;

  // return student id
  int getID() const;

  // return student full name and id (lastName, firstName (studentID))
  string getStudent() const;

  // adds a course to the students schedule
  bool addCourseToSchedule(const string &courseID, Course *name);

  // removes a course from the students schedule
  bool removeCourseFromSchedule(const string &courseID);
};

#endif