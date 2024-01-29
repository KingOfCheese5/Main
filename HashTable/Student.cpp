#include <iostream>
#include "Student.h"

using namespace std;
//getters for student
//return functions from Student.h

Student::Student(){
  
}

char* Student::getFirstName() {
  return firstName;

}

char* Student::getLastName() {
  return lastName;
  
}

int Student::getID() {
  return studentID;
}

float Student:: getGPA() {
  return GPA;

}

void Student::setID(int newID) {
  studentID = newID;
}

void Student::setGPA(float newGPA) {
  GPA = newGPA;
}
