#ifndef STUDENT
#define STUDENT

#include <iostream>

using namespace std;

class Student {

 public:
  //Functions for Student class
  char* getFirstName();
  char* getLastName();
  int getStudentID();
  float getGPA();
  //all variables are public
  char firstName[81];
  char lastName[81];
  int studentID = 0;
  float GPA = 0;
};

#endif
