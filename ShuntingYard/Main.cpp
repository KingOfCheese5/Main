#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include "Node.h"

//check rao code later

int isMath(char c);
void printStack(Node* stackHead);

using namespace std;

int main() {

  Node* stackHead = NULL;
  Node* queueHead = NULL;
  Node* queueTail = NULL;
  Node* newNode;
  Node* current;
  char readInput[50];
  
  cout << "Enter a mathematical expression" << endl;
  cout << "The expression should be in infix form" << endl;
  cin.get(input, 81);
  cin.ignore(81, '\n');

  for(int i = 0; i < strlen(readInput); i++) {
    if(isdigit(readInput[i] == 0) {
	cout << "number" << endl;
      }
      else if(isMath[i] == 0) {
      	cout << "math" << endl;
      }
      else if(){
	cout << "who" << endl;
      }      

  return 0;
}
int isMath(char c) {
  //test if character is mathematical expression
  if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^')) {
      return 0;
  }

  //1 = false
  else {
    return 1;
  }
}

void printStack(Node* stackHead) {
  if (stackHead == NULL) {
    cout << "No sta" << endl;
  }
  else if (stackHead->getNext() != NULL) {
    cout << "printing: " << stackHead->getChar() << endl;
    printStack(stackHead->getNext());
  }
  else {
    cout << "printing: " << stackHead->getChar() << endl << endl;
  }
}

int precedence(char nodeChar) {
  if (nodeChar == '^') {
    return 4;
  }
  else if ((nodeChar == '*') || (nodeChar == '/')) {
    return 3;
  }
  else if ((nodeChar == '+') || (nodeChar == '-')) {
    return 2;
  }
  else {
    return 0;
  }
}
