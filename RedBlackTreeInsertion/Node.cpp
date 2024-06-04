#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

#include <iostream>
#include "node.h"

using namespace std;

Node::Node() { //Constructor
  left = NULL;
  right = NULL;
  parent = NULL;
  data = 0;
  color = 1; //black = 0, red = 1
}

Node::~Node() { //Destructor
  left = NULL;
  right = NULL;
  parent = NULL;
}

//Setters
void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setParent(Node* newParent) {
  parent = newParent;
}

void Node::setData(int newData) {
  data = newData;
}

void Node::setColor(int newColor) {
  color = newColor;
}

//Getters
Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getParent() {
  return parent;
}

//vikram vasudevan
Node* Node::getUncle(){
  Node* uncle = new Node();
  if(this->getParent()->getData() <= this->getData()){
    uncle = this->getParent()->getLeft();
  }
  else if(this->getParent()->getData() > this->getData()){
    uncle = this->getParent()->getRight();
  }
  return uncle;
}

int Node::getData() {
  return data;
}

int Node::getColor() {
  return color;
}
