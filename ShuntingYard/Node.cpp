#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//constructor
Node::Node() {
  next = NULL;
  right = NULL;
  left = NULL;
}

Node::Node(char newc) {
  c = newc;
  next = NULL;
  left = NULL;
  right = NULL;
}

Node* Node::getNext() {
  return next;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

char Node::getChar() {
  return c;
}

void Node::setNext(Node* nextNode){
    next = nextNode;
}

void Node::setLeft(Node* newNode) {
  left = newNode;
}

void Node::setRight(Node* newNode) {
  right = newNode;
}

Node* Node::getPrev() {
  return prev;
}

void Node::setPrev(Node* prevNode) {
  prev = prevNode;
}

void Node::setChar(char newc) {
  c = newc;
}

Node::~Node() {
  next = NULL;
  left = NULL;
  right = NULL;
}
