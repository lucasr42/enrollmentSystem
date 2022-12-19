#include "enrollmentsystem.h"
#include "university.h"

#include <cassert>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * @brief Destroy the Enrollment System:: Enrollment System object
 *
 */
EnrollmentSystem::~EnrollmentSystem() {
  for (auto i : universities) {
    delete i.second;
    i.second = nullptr;
  }
}

/**
 * @brief adds a university to the enrollment system
 *
 * @param name name of university
 * @return true if uni is added
 * @return false if uni is not added
 */
bool EnrollmentSystem::addUniversity(const string &name) {
  if (!universities[name]) {
    auto *school = new University(name);
    universities[name] = school;
    return true;
  }
  return false;
}

/**
 * @brief Set university object to work
 *
 * @param name Name of University
 * @return true if uni is set
 * @return false if uni is not set
 */
bool EnrollmentSystem::setCurrentUniversity(const string &name) {
  return (currentUniversity = universities[name]);
}

/**
 * @brief returns the name of the university
 *
 * @return string the name of the university
 */
string EnrollmentSystem::getUniversityName() const {
  return currentUniversity->getName();
}

/**
 * @brief Reads student id numbers and names from .txt file into student objects
 *
 * @param filename Name of file to read from
 * @return true If file is read
 * @return false If file is unable to open
 */
bool EnrollmentSystem::readStudentList(const string &filename) {
  string studentNumber;
  string firstName;
  string lastName;
  int stuNum = 0;
  char space = ' ';

  ifstream inFile;
  inFile.open(filename);

  if (!inFile) {
    cerr << "unable to open file: " << filename << endl;
    return false;
  }

  while (!inFile.eof()) {
    getline(inFile, studentNumber, space);
    if (studentNumber != "") {
      stuNum = stoi(studentNumber);
      getline(inFile, firstName, space);
      getline(inFile, lastName);
      currentUniversity->addStudent(stuNum, lastName, firstName);
    }
  }
  return true;
}

/**
 * @brief Reads course id numbers and names from .txt file into course objects
 *
 * @param filename Name of file to read from
 * @return true If file is read
 * @return false If file is unable to open
 */
bool EnrollmentSystem::readCourseList(const string &filename) {
  string courseNumber;
  string courseName;
  char space = ' ';

  ifstream inFile;
  inFile.open(filename);

  if (!inFile) {
    cerr << "unable to open file: " << filename << endl;
    return false;
  }

  while (!inFile.eof()) {
    getline(inFile, courseNumber, space);
    getline(inFile, courseName);
    currentUniversity->addCourse(courseNumber, courseName);
  }
  return true;
}

/**
 * @brief Reads student ID's and course ID's from .txt file to add students to
 * courses
 *
 * @param filename Name of file to read from
 * @return true If file is read
 * @return false If file is unable to open
 */
bool EnrollmentSystem::readEnrollmentInfo(const string &filename) {
  return currentUniversity->readEnrollmentInfo(filename);
}

/**
 * @brief Removes a student from a course
 *
 * @param studentID Student to remove
 * @param courseNumber Course to remove from
 * @return true If student is removed from course
 * @return false If studentID or course number do not match format or if student
 * is not dropped from course
 */
bool EnrollmentSystem::dropCourse(int studentID, const string &courseNumber) {
  string idSize = to_string(studentID);
  if (idSize.length() != 4 && courseNumber.length() != 6) {
    return false;
  }
  return currentUniversity->dropCourse(studentID, courseNumber);
}

/**
 * @brief Add a student to a given course
 *
 * @param studentID Student to add
 * @param courseNumber Course to add student to
 * @return true If student is add to course
 * @return false If studentID or course number do not match format or if student
 * is not added to course
 */
bool EnrollmentSystem::addCourse(int studentID, const string &courseNumber) {
  string idSize = to_string(studentID);
  if (idSize.length() != 4 || courseNumber.length() != 6) {
    return false;
  }
  return currentUniversity->enrollStudentToCourse(studentID, courseNumber);
}

/**
 * @brief Checks if student is in a given course
 *
 * @param studentID Student to check for
 * @param courseNumber Course to check in
 * @return true If student is in course
 * @return false If studentID or course number do not match format or if student
 * is not enrolled in course
 */
bool EnrollmentSystem::isInCourse(int studentID,
                                  const string &courseNumber) const {
  string idSize = to_string(studentID);
  if (idSize.length() != 4 || courseNumber.length() != 6) {
    return false;
  }
  return currentUniversity->isInCourse(studentID, courseNumber);
}

/**
 * @brief Returns a string of the students schedule
 *
 * @param studentID Student to find schedule for
 * @return string Students schedule
 */
string EnrollmentSystem::getEnrolledCourses(int studentID) const {
  return currentUniversity->getEnrolledCourses(studentID);
}

/**
 * @brief Returns a string of a given course's title
 *
 * @param courseNumber Course to find title
 * @return string Course title
 */
string EnrollmentSystem::getCourseTitle(const string &courseNumber) {
  return currentUniversity->getCourseTitle(courseNumber);
}

/**
 * @brief Gets a list of students in a given course organized by last name
 *
 * @param courseNumber Course to check student roll
 * @return string List of students enrolled in course
 */
string
EnrollmentSystem::getClassListByLastName(const string &courseNumber) const {
  return currentUniversity->getClassListByLastName(courseNumber);
}

/**
 * @brief Gets a list of students in a given course organized by student ID
 *
 * @param courseNumber Course to check student roll
 * @return string List of students enrolled in course
 */
string EnrollmentSystem::getClassListByID(const string &courseNumber) const {
  return currentUniversity->getClassListByID(courseNumber);
}