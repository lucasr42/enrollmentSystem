#include "course.h"
#include "student.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

/**
 * @brief Construct a new Course:: Course object
 *
 * @param cID Course ID number
 * @param name Course Name
 */
Course::Course(const string &cID, const string &name)
    : courseID(cID), courseTitle(name){};

/**
 * @brief Checks if a student is enrolled in this course
 *
 * @param sID Student to look for
 * @return true If student is enrolled in this course
 * @return false If student is not enrolled in course
 */
bool Course::isEnrolled(int sID) const { return students.count(sID) != 0; }

/**
 * @brief Adds a student to this course
 *
 * @param student Student to add to course
 * @return true If student is enrolled in the course
 * @return false If student is not added to course
 */
bool Course::enroll(Student *student) {
  bool success = false;
  if (!students[student->getID()]) {
    // adds student to course map
    students[student->getID()] = student;
    success = true;
  }
  return success;
}

/**
 * @brief Removes a student from the course
 *
 * @param sID Student to remove
 * @return true If student is removed
 * @return false If student is not removed
 */
bool Course::dropStudent(int sID) {
  bool success = false;
  if (students[sID]) {
    // Removes student from this course
    students.erase(sID);
    success = true;
  }
  return success;
}

/**
 * @brief Returns a list of all students enrolled in course organized by last
 * name
 *
 * @return string List of students organized by last name
 */
string Course::getClassListByLastName() const {
  set<string> orderListLast;
  string studentList;
  studentList += "[";
  for (auto i : students) {
    // getStudent() organized by last name
    // set organizes by last name
    orderListLast.insert(i.second->getStudent());
  }
  for (auto j : orderListLast) {
    studentList += (j + ", ");
  }
  studentList.pop_back();
  studentList.pop_back();
  studentList += "]";
  return studentList;
}

/**
 * @brief Returns a list of students enrolled in this course organized by
 * student ID number
 *
 * @return string List of students organized by student ID number
 */
string Course::getClassListByID() const {
  string studentList;
  studentList += "[";
  for (auto i : students) {
    studentList += (i.second->getStudent() + ", ");
  }
  studentList.pop_back();
  studentList.pop_back();
  studentList += "]";
  return studentList;
}
