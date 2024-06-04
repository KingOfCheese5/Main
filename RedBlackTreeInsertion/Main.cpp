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
void leftRotate(Node* &root, Node* cur);
void rightRotate(Node* &root, Node* cur);

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
	node->setData(temp);
	add(root, root, node, temp);
      }
    }
    //input by file
    else if(strcmp(input, "file") == 0) {
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
        node->setData(*iter);
	node->setColor(1);
	add(root, root, node, *iter);
      }
	stream1.close();
	cout << "finished" << endl;
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
  else if(cur->getData() >= node->getData()){
    if(cur->getLeft() == NULL){
      cur->setLeft(node);
      balance(root, cur);
    }
    else{
      add(root, cur->getLeft(), node, data);
    }
  }

  //make right subtree
  else if(cur->getData() < node->getData()){
    if(cur->getRight() == NULL){
      cur->setRight(node);
      balance(root, cur);
    }
    else{
      add(root, cur->getRight(), node, data);
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
  cout << cur->getData() << endl;
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
    if(cur->getParent() != NULL) {
      if(cur->getParent()->getColor() == 0) {
	return;
      }
      //case 3: parent and uncle are red
      if(grandparent != NULL) {
	if((cur->getParent()->getColor() == 1) && (cur->getParent()->getUncle() != NULL) && (cur->getParent()->getUncle()->getColor() == 1)) {
	  cur->getParent()->setColor(0);
	  cur->getUncle()->setColor(0);
	  grandparent->setColor(1);
	  balance(root, cur);
	}
	//case 4: left parent, right node
	if (cur->getParent()->getParent()->getLeft() == cur->getParent() && cur->getParent()->getRight() == cur) {
	  leftRotate(root, cur);
	}
	//Parent is right and node is left
	else if (cur->getParent()->getParent()->getRight() == cur->getParent() && cur->getParent()->getLeft() == cur) {
	  rightRotate(root, cur);
	}
	//case 5: run after case 4, uncle black, parent & cur on one side
	if(cur->getParent()->getData() < cur->getParent()->getParent()->getData() && cur->getData() < cur->getParent()->getData()) {
	  if(cur->getParent()->getData() > cur->getData()){
	    rightRotate(root, parent);
	    cur->getParent()->setColor(0);
	    grandparent->setColor(1);
	  }
	  else {
	    leftRotate(root, parent);
            cur->getParent()->setColor(0);
            grandparent->setColor(1);
	  }
	}
	else if(cur->getParent()->getData() >= cur->getParent()->getParent()->getData() && cur->getData() >= cur->getParent()->getData()) {
	  if(cur->getParent()->getData() > cur->getData()){
            rightRotate(root, parent);
            cur->getParent()->setColor(0);
            grandparent->setColor(1);
          }
          else {
            leftRotate(root, parent);
            cur->getParent()->setColor(0);
            grandparent->setColor(1);
          }
	}
      }
    }
  }
}

void leftRotate(Node* &root, Node* cur) {
   Node* rightN = cur->getRight();
   //start rotation
   cur->setRight(rightN->getLeft());
   if (cur->getLeft() != NULL) {
     cur->getLeft()->setParent(cur);
   }
   rightN->setParent(cur->getParent());
   //if working with root
   if (cur->getParent() == NULL) {
     root = rightN;
   }
   else if (cur == (cur->getParent())->getLeft()) {
     cur->getParent()->setLeft(rightN);
   }
  else {
      cur->getParent()->setRight(rightN);
   }
   rightN->setLeft(cur);
   cur->setParent(rightN);
}

void rightRotate(Node* &root, Node* cur) {
  Node* leftN = cur->getLeft();
  //start rotation
  cur->setLeft(leftN->getRight());
  if (cur->getLeft() != NULL) {
    cur->getLeft()->setParent(cur);
  }
  leftN->setParent(cur->getParent());
  //root
  if(cur->getParent() == NULL) {
    root = leftN;
  }
  else if(cur = cur->getParent()->getRight()){
    cur->getParent()->setRight(leftN);
  }
  else {
    cur->getParent()->setLeft(leftN);
  }
  leftN->setRight(cur);
  cur->setParent(leftN);
}

    
    
