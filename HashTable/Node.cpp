#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(Student* studentIN){
  student = studentIN;
  head = NULL;
}

Node::~Node(){
  delete student;
}

void Node::setNext(Node* &node){
  head = node;
}

Node* Node::getNext(){
  return head;
}

Student* Node::getStudent(){
  return student;
}

void Node::nullifyHead(){
  head = NULL;
}
