#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include "Node.h"

int isMath(char c);
void push(Node* newNode, Node* &stackHead);
void enqueue(Node* newNode, Node* &queueHead, Node* &queueEnd);
void pop(Node* &current, Node* &stackHead);
void dequeue(Node* &current, Node* &queueHead, Node* &queueEnd);
char peek(Node* &stackHead);
void makeTree(Node* &queueHead, Node* &queueEnd, Node* &treeHead, Node* &BinaryTreeStackHead);
void pushTree(Node* newNode, Node* &BinaryTreeStackHead);
void popTree(Node* &current, Node* &BinaryTreeStackHead);
void prefix(Node* current);
void postfix(Node* current);
void infix(Node* current);

using namespace std;

int main() {

  Node* stackHead = NULL;
  Node* queueHead = NULL;
  Node* queueEnd = NULL;
  Node* newNode;
  Node* current;
  Node* BinaryTreeStackHead = NULL;
  Node* treeHead = NULL;
  char readInput[181];
  
  cout << "Enter a mathematical expression in infix form" << endl;
  cin.get(readInput, 181);
  cin.ignore(181, '\n');
  
  for(int i = 0; i < strlen(readInput); i++) {
    
    newNode = new Node(readInput[i]);

    //if it's character, push onto stack
    if(isMath(readInput[i] == 0)) {
      push(newNode, stackHead);
    }
    //if it's right parenthesis, pop from stack and onto queue until stackHead is left parenthesis
    else if(readInput[i] == ')') {
      Node* nodeTemp;
      bool running = true;
      while(running == true){
	if(peek(stackHead) != '('){
	  pop(nodeTemp, stackHead);
	  enqueue(nodeTemp, queueHead, queueEnd);
	}
	else {
	  pop(nodeTemp, stackHead);
	  running = false;
	}
      }
      
    }
    else if (isdigit(readInput[i])) {
      enqueue(newNode, queueHead, queueEnd);
    }
  }

  bool running = true;
  Node* temp;
  //queue stack until stack is empty
  while(running == true){
    
    if(stackHead != NULL){
      
      pop(temp, stackHead);
      enqueue(temp, queueHead, queueEnd);

    }
    else{
      running = false;
    }
  }

  //Make tree
  makeTree(queueHead, queueEnd, treeHead, BinaryTreeStackHead);
  running = true;
  char input[81];

  
  while(running == true) {
      cout << "Enter PREFIX, POSTFIX, INFIX, or QUIT" << endl;
      cin.get(input, 81);
      cin.ignore(81, '\n');

      if(strcmp(input, "PREFIX") == 0){
	prefix(treeHead);

      }
      else if(strcmp(input, "POSTFIX") == 0){
	postfix(treeHead);

      }

      else if(strcmp(input, "INFIX") == 0){
	infix(treeHead);
      }

      else if(strcmp(input, "QUIT") == 0){
	running = false;

    }
    
  }
  
  return 0;
}


int isMath(char c) {
  //test if character is mathematical expression
  if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^') || (c == '(')) {
      return 0;
  }

  //1 = false
  else {
    return 1;
  }
}

void push(Node* newNode, Node* &stackHead){//Add new node to stack
  stackHead = newNode->getNext();
  stackHead = newNode;
}

void pop(Node* &current, Node* &stackHead){//Remove the top most node of the stack
  current = stackHead;
  stackHead = stackHead->getNext();
}

char peek(Node* &stackHead){//Check value of the top most node on the stack
  return stackHead->c;
}

void dequeue(Node* &current, Node* &queueHead, Node* &queueEnd){//Remove from the queue
  current = queueHead;
  queueHead = queueHead->getNext();
}

void enqueue(Node* newNode, Node* &queueHead, Node* &queueEnd){//Add new node to the queue
  
  if(queueHead == NULL){
    newNode->setPrev(NULL);
    newNode->setNext(NULL);
    queueHead = newNode;
    queueEnd = newNode;
  }
  else{
    newNode->setPrev(queueEnd);
    queueEnd->setNext(newNode);
    newNode->setNext(NULL);
    queueEnd = newNode;
  } 
}

void makeTree(Node* &queueHead, Node* &queueEnd, Node* &treeHead, Node* &BinaryTreeStackHead) {
  bool running = true;
  Node* current;
  while (running) {
    if (isMath(queueHead->getChar()) == 1) {
      dequeue(current, queueHead, queueEnd);
      Node* BinaryTreeCurrent = new Node();
      BinaryTreeCurrent->setChar(current->getChar());
      pushTree(BinaryTreeCurrent, BinaryTreeStackHead);
    }
    else {
      dequeue(current, queueHead, queueEnd);
      Node* BinaryTreeCurrent = new Node();
      BinaryTreeCurrent->setChar(current->getChar());
      Node* point;
      popTree(point, BinaryTreeStackHead);
      BinaryTreeCurrent->setRight(point);
      popTree(point, BinaryTreeStackHead);
      BinaryTreeCurrent->setLeft(point);
      pushTree(BinaryTreeCurrent, BinaryTreeStackHead);
      treeHead = BinaryTreeCurrent;
    }
    if (queueHead == NULL) {
      running = false;
    }
  }
}

void pushTree(Node* newNode, Node*& BinaryTreeStackHead) {
  newNode->setNext(BinaryTreeStackHead);
  BinaryTreeStackHead = newNode;
}

void popTree(Node*& current, Node*& BinaryTreeStackHead) {
  current = BinaryTreeStackHead;
  BinaryTreeStackHead = BinaryTreeStackHead->getNext();
}

void prefix(Node* current){//Print prefix reccursively
  cout << current->getChar();
  if(current->getLeft() != NULL) {
    prefix(current->getLeft());
  }
  if(current->getRight() != NULL) {
    prefix(current->getRight());
  }
}

void postfix(Node* current){//Print postfix reccursively
  if(current->getLeft() != NULL) {
    postfix(current->getLeft());
  }
  if (current->getRight() != NULL) {
    postfix(current->getRight());
  }
  cout << current->getChar();
}

void infix(Node* current){//Print infix reccursively
  if(current->getLeft() != NULL) {
    infix(current->getLeft());
  }
  
  cout << current->getChar();
  
  if(current->getRight() != NULL) {
    infix(current->getRight());
  }
}
