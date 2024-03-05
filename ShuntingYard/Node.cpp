#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//constructor
Node::Node() {
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* nextNode){
    next = nextNode;
}

Node::~Node() {
  next = NULL;
}
