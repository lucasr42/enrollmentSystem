#include "university.h"
#include "student.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

/**
 * @brief Construct a new University:: University object
 *
 * @param uniName Name of school
 */
University::University(const string &uniName) : universityName(uniName){};

/**
 * @brief Destroy the University:: University object
 *
 */
University::~University() {
  for (auto i : students) {
    delete i.second;
    i.second = nullptr;
  }
  for (auto j : courses) {
    delete j.second;
    j.second = nullptr;
  }
}

bool University::readEnrollmentInfo(const string &filename) {
  string studentNumber;
  string courseNumber;
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
      getline(inFile, courseNumber);
      enrollStudentToCourse(stuNum, courseNumber);
    }
  }
  return true;
}

/**
 * @brief Returns the name of the university
 *
 * @return string University name
 */
string University::getName() const { return universityName; }

/**
 * @brief Enrolls a student at this university
 *
 * @param studentID ID number of student
 * @param lastName Last name of student
 * @param firstName First name of student
 * @return true If student is enrolled in university
 * @return false If student is already enrolled in university or is unable to be
 * added
 */
bool University::addStudent(int studentID, const string &lastName,
                            const string &firstName) {
  if (!students[studentID]) {
    auto *newStudent = new Student(studentID, lastName, firstName);
    students[studentID] = newStudent;
    return true;
  }
  return false;
}

/**
 * @brief Adds a course to this university
 *
 * @param courseID Course number to add
 * @param courseTitle Name of course to add
 * @return true If course is added
 * @return false If course already exists or is unable to add
 */
bool University::addCourse(const string &courseID, const string &courseTitle) {
  if (!courses[courseID]) {
    auto *newCourse = new Course(courseID, courseTitle);
    courses[courseID] = newCourse;
    return true;
  }
  return false;
}

/**
 * @brief Adds a give student to a given course
 *
 * @param studentID Student to add
 * @param courseID Course to add
 * @return true If student is successfully added to course
 * @return false If student already exists, course doesn't exists, or student is
 * unable to be added
 */
bool University::enrollStudentToCourse(int studentID, const string &courseID) {
  bool success = false;
  // Check if student and course exist
  if (students[studentID] && courses[courseID]) {
    Course *classToEnroll = nullptr;
    classToEnroll = courses[courseID];
    Student *studentToEnroll = nullptr;
    studentToEnroll = students[studentID];
    // Add student to course and course to student schedule
    if (classToEnroll->enroll(studentToEnroll)) {
      studentToEnroll->addCourseToSchedule(courseID, classToEnroll);
      success = true;
    }
  }
  return success;
}

/**
 * @brief Removes a given student from a given course
 *
 * @param studentID Student to add
 * @param courseID Course to add to
 * @return true If student is successfully removed from the course
 * @return false If course does not exist or student is unable to be dropped
 */
bool University::dropCourse(int studentID, const string &courseID) {
  bool success = false;
  if (students[studentID] && courses[courseID]) {
    courses[courseID]->dropStudent(studentID);
    students[studentID]->removeCourseFromSchedule(courseID);
    success = true;
  }
  return success;
}

/**
 * @brief Checks if a given student is enrolled in a given course
 *
 * @param studentID Student to look for
 * @param courseID Course to look in
 * @return true If student is enrolled in course
 * @return false If course doesn't exist or student is not enrolled in the
 * course
 */
bool University::isInCourse(int studentID, const string &courseID) const {
  Course *classToCheck = nullptr;
  classToCheck = courses.at(courseID);
  return classToCheck->isEnrolled(studentID);
}

/**
 * @brief Returns a list of the given students course schedule
 *
 * @param studentID Student to find schedule for
 * @return string Student schedule
 */
string University::getEnrolledCourses(int studentID) const {
  string classList;
  if (students.count(studentID) == 1) {
    Student *checkThisStudent = nullptr;
    checkThisStudent = students.at(studentID);
    classList = "[";
    for (auto i : checkThisStudent->studentSchedule) {
      classList += (i.second->courseID + ", ");
    }
    classList.pop_back();
    classList.pop_back();
    classList += "]";
  }
  return classList;
}

/**
 * @brief Returns the title of a course found of the course ID
 *
 * @param courseID The course to find the title of
 * @return string The course title
 */
string University::getCourseTitle(const string &courseID) const {
  Course *courseObjectToGetTitleOf = nullptr;
  courseObjectToGetTitleOf = courses.at(courseID);
  return courseObjectToGetTitleOf->courseTitle;
}

/**
 * @brief Returns the students enrolled in a given course organized by last name
 *
 * @param courseID Course to find students
 * @return string Student roll call
 */
string University::getClassListByLastName(const string &courseID) const {
  Course *courseRollCall = nullptr;
  courseRollCall = courses.at(courseID);
  return courseRollCall->getClassListByLastName();
}

/**
 * @brief Returns the students enrolled in a given course organized by student
 * ID
 *
 * @param courseID Course to find students
 * @return string Student roll call
 */
string University::getClassListByID(const string &courseID) const {
  Course *courseRollCall = nullptr;
  courseRollCall = courses.at(courseID);
  return courseRollCall->getClassListByID();
}