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
Node* Node::getUncle() {
  Node* parent = this->getParent();
  if (parent == NULL) return NULL;
  Node* grandparent = parent->getParent();
  if (grandparent == NULL) return NULL;
  
  if (parent == grandparent->getLeft()) {
    return grandparent->getRight();
  } else {
    return grandparent->getLeft();
  }
}

Node* Node::getSibling() {
  if (parent == NULL) {
    return NULL;
  }
  if (this == parent->getLeft()) {
    return parent->getRight();
  }
  return parent->getLeft();
}

int Node::getData() {
  return data;
}

int Node::getColor() {
  if(this == NULL) {
    return 0; //null = black
  }
  return color;
}
