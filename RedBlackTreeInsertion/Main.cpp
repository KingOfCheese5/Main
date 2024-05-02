#include <iostream>
#include <string>
#include <cstring>
#include "Node.h"
#include <vector>
#include <fstream>

using namespace std;

void add(Node* &root, Node* cur, Node* node, int data);
void print(Node* cur, int count);
void balance(Node* &root, Node* cur);

int main() {

  //create variables
  Node* root = NULL;
  char input[81];
  
  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char quitCopy[] = "quit";

  char addl[4];
  char printl[6];
  char quitl[5];

  cout << "RBT: Insertion" << endl;

  while(running == true) {

    cout << "Enter add, print, or quit" << endl;
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(quitl, quitCopy);

    cin.get(input, 81);
    cin.ignore(81, '\n');

    if(strcmp(input, addl) == 0) {
      cout << "input by 'console' or 'file' ?" << endl;
      char choice[20];
      cin.get(choice, 20);
      cin.ignore(20, '\n');

      //input by console
      if(strcmp(choice, "console") == 0) {
	cout << "Enter the number: " << endl;
	int temp;
	cin >> temp;
	cin.get();
	Node* node = new Node();
	node->setInformation(temp);
	add(root, root, node, temp);
      }
    }
    //input by file
    else if(strcmp(choice, "file") == 0) {
      cout << "How many numbers? " << endl;
      int numNums;
      cin >> numNums;
      cin.get();

      //just use hashtable code
      vector<int> numbers;
      fstream stream1;
      stream1.open("numbers.txt");
	
      int tempInt;
      while(stream1 >> tempInt) {
	numbers.push_back(tempInt);
      }

      vector <int> ::iterator iter = numbers.begin();
      for(iter = numbers.begin(); iter < numbers.end(); iter++){
	Node* node = new Node();
        node->setInformation(*iter);
	node->setColor(1);
	add(root, root, node);
      }
	stream1.close();
	cout << "finished" << endl;
    }
  }
    
    //print function
    if(strcmp(input, printl) == 0) {
      if(root != NULL) {
	print(root, 0);
      }
      else {
	//fail safe to prevent segFault
	cout << "There's nothing to print" << endl;
      }
    }

    if(strcmp(input, quitl) == 0) {
      cout << "Program exited" << endl;
      running = false;
    }
  }
  
  return 0;
}

void add(Node* &root, Node* cur, Node* node, int data) {
  
  //start tree
  if(root == NULL){
    root = node;
    root->setColor(0);
    root->setData(data);
  }
  //make left subtree
  else if(cur->getInformation() >= node->getInformation()){
    if(cur->getLeft() == NULL){
      cur->setLeft(node);
      balance(root, cur);
    }
    else{
      add(root, cur->getLeft(), node);
    }
  }

  //make right subtree
  else if(cur->getInformation() < node->getInformation()){
    if(cur->getRight() == NULL){
      cur->setRight(node);
      balance(root, cur);
    }
    else{
      add(root, cur->getRight(), node);
    }
  }
}

void print(Node* cur, int count) {

  //start from left
  if(cur->getLeft() != NULL){
    print(cur->getLeft(), count + 1);
  }

  //add spaces
  for(int i = 0; i < count; i++){
    cout << '\t';
  }

  //print out right child last
  cout << cur->getInformation() << endl;
  if(cur->getRight() != NULL) {
    print(cur->getRight(), count + 1);
  }
}

void balance(Node* &root, Node* cur) {
  Node* parent = NULL;
  Node* grandparent = NULL;
  parent = cur->getParent();
  grandparent = parent->getParent();
  //case one: new tree, root is added
  if(root == cur) {
    root->setColor(0);
    //case two: parent is black
    if(cur->getParent() !- NULL) {
      if(cur->getParent()->getColor() == 0) {
	return;
      }
      //case 3: parent and uncle are red
      if(cur->getGrandparent() != NULL) {
	if((cur->getParent()->getColor() == 1) && (cur->getParent()->getUncle() != NULL) && (cur->getParent()->getUncle()->getColor() == 1)) {
	  cur->getParent()->setColor(0);
	  cur->getUncle()->setColor(0);
	  cur->getGrandparent()->setColor(1);
	  balance(root, cur);
	}
	//case 4: left parent, right node
	if (newNode->getParent()->getParent()->getLeft() == newNode->getParent() && newNode->getParent()->getRight() == newNode) {
	  // Change parents and children
	  Node* tempParent = newNode->getParent();
	  Node* tempLeft = newNode->getLeft();
	  newNode->getParent()->getParent()->setLeft(newNode);
	  newNode->setParent(newNode->getParent()->getParent());
	  newNode->setLeft(tempParent);
	  newNode->getLeft()->setParent(newNode);
	  // Set right node if it exists
	  if (tempLeft != NULL) {
	    tempParent->setRight(tempLeft);
	    tempParent->getRight()->setParent(newNode->getLeft());
	  }
	  else {
	    tempParent->setRight(NULL);
	  }
	  newNode = newNode->getLeft();

	}
	//Parent is right and node is left
	else if (newNode->getParent()->getParent()->getRight() == newNode->getParent() && newNode->getParent()->getLeft() == newNode) {
	  // Change parents and children
	  Node* tempParent = newNode->getParent();
	  Node* tempRight = newNode->getRight();
	  newNode->getParent()->getParent()->setRight(newNode);
	  newNode->setParent(newNode->getParent()->getParent());
	  newNode->setRight(tempParent);
	  newNode->getRight()->setParent(newNode);
	  // Set left node if it exists
	  if (tempRight != NULL) {
	    tempParent->setLeft(tempRight);
	    tempParent->getLeft()->setParent(newNode->getRight());
	  }
	  else {
	    tempParent->setLeft(NULL);
	  }
	}
	newNode = newNode->getRight();
	case5(treeRoot, newNode);
      }
    }
  }
}

void leftRotate(Node* &root, Node* cur) {
   Node* rightP = cur->getRight();
   //start rotation
   cur->setRight(rightP->getLeft());
   if (cur->getLeft() != NULL) {
     cur->getLeft()->setParent(cur);
   }
   rightP->setParent(cur->getParent());
   //if working with root
   if (cur->getParent() == NULL) {
     root = rightP;
   }
   else if (cur == (cur->getParent())->getLeft()) {
     cur->getParent()->setLeft(rightP);
   }
  else {
      cur->getParent()->setRight(rightP);
   }
   rightP->setLeft(cur);
   cur->setParent(rightP);
}

void rightRotate(Node* &root, Node* cur) {
  Node* leftP = cur->getLeft();
  //start rotation
  cur->setLeft(leftP->getRight());
  if (cur->getLeft() != NULL) {
    cur->getLeft()->setParent(cur);
  }
  leftP->setParent(cur->getParent());
  //root
  if(cur->getParent() == NULL) {
    root = leftP;
  }
  else if(cur = cur->getParent()->getRight()){
    cur->getParent()->setRight(leftP);
  }
  else {
    cur->getParent()->setLeft(leftP);
  }
  leftP->setRight(cur);
  cur->setParent(leftP);
}

    
    
