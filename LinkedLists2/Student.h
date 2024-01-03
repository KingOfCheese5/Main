#ifndef STUDENT
#define STUDENT

#include <iostream>

using namespace std;

class Student {

 public:
  //Functions for Student class
  Student();
  char* getFirstName();
  char* getLastName();
  int getID();
  float getGPA();
  void setID(int newID);
  void setGPA(float newGPA);
  //all variables are public
  char firstName[81];
  char lastName[81];
  int studentID = 0;
  float GPA = 0;
};

#endif
