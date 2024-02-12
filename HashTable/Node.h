#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node{
public:
  Node(Student* studentIN);
  void setNext(Node* node);
  void setTail(Node* &node);
  Node* getNext();
  ~Node();
  Student* getStudent();
  void nullifyHead();
protected:
  Student* student;
  Node* head;
};

#endif
