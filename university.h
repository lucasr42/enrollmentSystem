#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "course.h"
#include "student.h"
#include <map>
#include <string>

using namespace std;

class University {
  friend class EnrollmentSystem;

private:
  // University name
  string universityName;

  // Holds all students enrolled at current university
  map<int, Student *> students;

  // Holds all course available at current university
  map<string, Course *> courses;

public:
  // Construct a University object and initializes university name, adds student
  // to enrollment list, adds a course to course list
  explicit University(const string &uniName);

  // copy constructor
  University(const University &other) = delete;

  // move constructor
  University(University &&other) = delete;

  // assignment operator
  University &operator=(const University &uni) = delete;

  // move operator
  University &operator=(const University &&uni) = delete;

  // Destroys university object and deletes all pointers
  ~University();

  // read course enrollment information for each university and student
  bool readEnrollmentInfo(const string &filename);

  // Returns current university name
  string getName() const;

  // add the given student's record
  bool addStudent(int studentID, const string &lastName,
                  const string &firstName);

  // add the given course to the univeristy course list
  bool addCourse(const string &courseID, const string &courseTitle);

  // add the given student to the course
  bool enrollStudentToCourse(int studentID, const string &courseID);

  // drop the course
  bool dropCourse(int studentID, const string &courseID);

  // return true if student is registor in the course
  bool isInCourse(int studentID, const string &courseID) const;

  // Return the courses student is enrolled in
  // The returned courses are separated by commas and sorted by course name
  string getEnrolledCourses(int studentID) const;

  // Return the title for the course
  string getCourseTitle(const string &courseID) const;

  // Return class list sorted by last name of students
  string getClassListByLastName(const string &courseID) const;

  // Return class list sorted by id of students
  string getClassListByID(const string &courseID) const;
};

#endif