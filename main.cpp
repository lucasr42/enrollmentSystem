
#include "enrollmentsystem.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

// check enrollment system
void test1() {
  EnrollmentSystem enrollSys;
  assert(enrollSys.addUniversity("UWB"));
  assert(!enrollSys.addUniversity("UWB"));
  assert(enrollSys.addUniversity("UW Seattle"));
  assert(enrollSys.addUniversity("UW Tacoma"));
  assert(!enrollSys.setCurrentUniversity("UWx"));
  assert(enrollSys.setCurrentUniversity("UWB"));
  assert(enrollSys.getUniversityName() == "UWB");
  // read data
  assert(enrollSys.readCourseList("data-courses.txt"));
  assert(enrollSys.readStudentList("data-students.txt"));
  assert(enrollSys.readEnrollmentInfo("data-enrollments.txt"));
  // check courses
  assert(!enrollSys.addCourse(999, "CSS342"));
  assert(!enrollSys.addCourse(1070, "CSS3422"));
  assert(!enrollSys.isInCourse(1070, "CSS342"));
  assert(enrollSys.addCourse(1070, "CSS342"));
  assert(enrollSys.dropCourse(1070, "CSS343"));
  assert(enrollSys.getCourseTitle("CSS342") ==
         "Data Structures, Algorithms, and Discrete Mathematics I");
  // check enrollments
  assert(enrollSys.getEnrolledCourses(1070) == "[CSS110, CSS173, CSS342]");
  string c342byLastName =
      "[Collins, Cassandra (1070), Evans, Juan (1401), Gonzalez, Holly (1223), "
      "Henderson, Daniel (1364), Taylor, Alexander (1986), Thompson, Christine "
      "(1386), Watson, Alex (1211)]";
  assert(enrollSys.getClassListByLastName("CSS342") == c342byLastName);
  string c342byID =
      "[Collins, Cassandra (1070), Watson, Alex (1211), Gonzalez, Holly "
      "(1223), Henderson, Daniel (1364), Thompson, Christine (1386), Evans, "
      "Juan (1401), Taylor, Alexander (1986)]";
  assert(enrollSys.getClassListByID("CSS342") == c342byID);
}

// run all tests
int main() {
  test1();
  cout << "Done." << endl;
}
