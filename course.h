#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration
class Student;

class Course {
  friend class Student;
  friend class University;
  friend class EnrollmentSystem;

private:
  // Holds course id
  string courseID;
  // Course name
  string courseTitle;
  // Holds Student objects that are enrolled in this course
  map<int, Student *> students;

public:
  // constructor
  explicit Course(const string &cID = "", const string &name = "");

  // copy constructor
  Course(const Course &other) = delete;

  // move constructor
  Course(const Course &&other) = delete;

  // assignment operator
  Course &operator=(const Course &courseID) = delete;

  // move operator
  Course &operator=(const Course &&courseID) = delete;

  // destructor
  ~Course() = default;

  // return true if student is enrolled
  bool isEnrolled(int sID) const;

  // add student to the course. return true if student is successfully added to
  // the course. return false if the student is already registered
  bool enroll(Student *student);

  // remove student from the course. return true if student is successfully
  // removed from the course. false if student is not in the course
  bool dropStudent(int sID);

  // return the list of students enrolled in this course sorting by student last
  // name
  string getClassListByLastName() const;

  // return the list of students enrolled in this course sorting by student id
  string getClassListByID() const;
};

#endif