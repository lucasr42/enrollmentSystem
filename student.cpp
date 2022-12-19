#include "student.h"
#include "course.h"

#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Construct a new Student:: Student object
 *
 * @param sID Student ID number
 * @param lastName Student last name
 * @param firstName Student first name
 */
Student::Student(int sID, const string &lastName, const string &firstName)
    : studentID(sID), studentLastName(lastName), studentFirstName(firstName){};

/**
 * @brief Returns student ID
 *
 * @return int students ID number
 */
int Student::getID() const { return studentID; };

/**
 * @brief Returns a string with students last name, first name, student number
 * formatted as last, first (num)
 *
 * @return string Students information
 */
string Student::getStudent() const {
  string num = to_string(studentID);
  string studentInfo =
      studentLastName + ", " + studentFirstName + " (" + num + ")";
  return studentInfo;
}

/**
 * @brief Adds a course to this students schedule
 *
 * @param courseID ID number of course to add
 * @param name Course object to add to map
 * @return true If course is added
 * @return false If course already exists or course is not added
 */
bool Student::addCourseToSchedule(const string &courseID, Course *name) {
  bool success = false;
  if (!studentSchedule[courseID]) {
    studentSchedule[courseID] = name;
    success = true;
  }
  return success;
}

/**
 * @brief Removes a course from this students schedule
 *
 * @param courseID ID number of course to remove
 * @return true If course is removed
 * @return false If course doesn't exist or fails to remove
 */
bool Student::removeCourseFromSchedule(const string &courseID) {
  bool success = false;
  if (studentSchedule[courseID]) {
    studentSchedule.erase(courseID);
    success = true;
  }
  return success;
}