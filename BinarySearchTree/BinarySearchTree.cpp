//Binary Search Tree
//Date: 3/20/24
//Description: Take in inputs and sort using binary tree algorithm. Allow users to print and delete components of the tree.

#include <iostream>
#include <string>
#include <cstring>
#include "Node.h"
#include <vector>
#include <fstream>
using namespace std;

void add(Node* &root, Node* cur, Node* node);
void print(Node* cur, int count);
int search(Node* cur, int value);
void remove(Node* &root, Node* cur, int value);
int hasChild(Node* node);

int main() {

  //create variables
  Node* root = NULL;
  char input[81];
  
  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char deleteCopy[] = "delete";
  char quitCopy[] = "quit";
  char searchCopy[] = "search";

  char addl[4];
  char printl[6];
  char deletel[7];
  char quitl[5];
  char searchl[8];

  cout << "Welcome to Binary Search Tree" << endl;
  
  while(running == true) {

    cout << "Enter add, print, delete, search, or quit" << endl;
    
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(deletel, deleteCopy);
    strcpy(quitl, quitCopy);
    strcpy(searchl, searchCopy);

    cin.get(input, 81);
    cin.ignore(81, '\n');

    if(strcmp(input, addl) == 0) {
      cout << "input by 'console' or 'file' ?" << endl;
      char choice[20];
      cin.get(choice, 20);
      cin.ignore(20, '\n');

      //input by console
      if(strcmp(choice, "console") == 0) {
	cout << "How many numbers? " << endl;
	int numNums;
	cin >> numNums;
	cin.get();

	cout << "Enter your string of numbers: " << endl;
	for(int i = 0; i < numNums; i++){
	  int temp;
	  cin >> temp;
	  cin.get();
	  Node* node = new Node();
	  node->setInformation(temp);
	  add(root, root, node);
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

    //delete function
    if(strcmp(input, deletel) == 0) {
      cout << "what value do you want to remove?" << endl;
      int removeMe;
      cin >> removeMe;
      cin.get();

      remove(root, root, removeMe);
    }

    //search function
    if(strcmp(input, searchl) == 0) {
      cout << "what value do you want to search for?" << endl;
      int searchFor;
      cin >> searchFor;
      cin.get();

      if(search(root, searchFor) == 0) {
	cout << "value found" << endl;
      }
      else if(search(root, searchFor) == 1) {
	cout << "value not found" << endl;
      }
    }

    //quit
    if(strcmp(input, quitl) == 0) {
      cout << "Program exited" << endl;
      running = false;
    }
  }
}

void add(Node* &root, Node* cur, Node* node) {

  //start tree
  if(root == NULL){
    root = node;
  }
  //make left subtree
  else if(cur->getInformation() >= node->getInformation()){
    if(cur->getLeft() == NULL){
      cur->setLeft(node);
    }
    else{
      add(root, cur->getLeft(), node);
    }
  }

  //make right subtree
  else if(cur->getInformation() < node->getInformation()){
    if(cur->getRight() == NULL){
      cur->setRight(node);
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

//return either true or false(0 or 1)

int search(Node* cur, int value){

  //if search input is greater, start from right side
  if(value > cur->getInformation()){
    
    if(cur->getRight() != NULL){

      return search(cur->getRight(), value);
    }
  }

  //if search input is less, go left
  else if(value < cur->getInformation()){
    
    if(cur->getLeft() != NULL){
      
      return search(cur->getLeft(), value);
    }
  }

  //return 0 if value is found
  else if(value == cur->getInformation()){
    return 0;
  }
  
  return 1;
}

void remove(Node* &root, Node* cur, int value) {

  //delete root and no subtrees
  if(value == root->getInformation()) {
    if(hasChild(root) == 3) {
      delete root;
      root->~Node();
      root = NULL;
      cout << "deleted" << endl;
    }
    //delete root and one sided
    else if(hasChild(root) == 1) {
      Node* temp = root->getLeft();
      delete root;
      root->~Node();
      root = temp;
    }
    else if(hasChild(root) == 2) {
      Node* temp = root->getRight();
      delete root;
      root->~Node();
      root = temp;
    }
    //if deleting root, and two children
    else if(hasChild(root) == 0) {
      //store the value of the new root, then delete the node and replace root
      Node* temp = root->getRight();
      while(temp->getLeft() != NULL){
	temp = temp->getLeft();
      }
      Node* temp2 = new Node();
      temp2->setInformation(temp->getInformation());
      remove(root, root, temp->getInformation());
      temp2->setLeft(root->getLeft());
      temp2->setRight(root->getRight());
      root = temp2;
    }
  }
  //if value is less than current node
  else if(value < cur->getInformation()) {
    //use recursion
    if(cur->getLeft()->getInformation() != value){
      remove(root, cur->getLeft(), value);
    }
    else {
      if(cur->getLeft()->getLeft() == NULL && cur->getLeft()->getRight() == NULL){
	delete cur->getLeft();
        cur->setLeft(NULL);
      }
      else if(cur->getLeft()->getLeft() != NULL && cur->getLeft()->getRight() == NULL){
	Node* tempNode = cur->getLeft()->getLeft();
        delete cur->getLeft();
	cur->setLeft(tempNode);
      }
      else if(cur->getLeft()->getLeft() == NULL && cur->getLeft()->getRight()!= NULL){
	Node* tempNode = cur->getLeft()->getRight();
        delete cur->getLeft();
        cur->setLeft(tempNode);
      }
      else if(cur->getLeft()->getLeft() != NULL && cur->getLeft()->getRight() != NULL){
	Node* tempNode = cur->getLeft()->getLeft();
	while(tempNode->getRight() != NULL) {
	  tempNode = tempNode->getRight();
	}
	Node* tempNode2 = new Node();
        tempNode2->setInformation(tempNode->getInformation());
	remove(root, cur, tempNode->getInformation());
        tempNode2->setLeft(cur->getLeft()->getLeft());
        tempNode2->setRight(cur->getLeft()->getRight());
	cur->setLeft(tempNode2);
      }
    }
  }
  //if value is greater than current node
  else if(value > cur->getInformation()) {
    //move right, use recursion
    if(cur->getRight()->getInformation() != value){
      remove(root, cur->getRight(), value);
    }
    else {
      if(cur->getRight()->getLeft() == NULL && cur->getRight()->getRight() == NULL){
	delete cur->getRight();
	cur->setRight(NULL);
      }
      else if(cur->getRight()->getLeft() != NULL && cur->getRight()->getRight() == NULL){
	Node* tempNode = cur->getRight()->getLeft();
        delete cur->getRight();
        cur->setRight(tempNode);
      }
      else if(cur->getRight()->getLeft() == NULL && cur->getRight()->getRight()!= NULL){
	Node* tempNode = cur->getRight()->getRight();
        delete cur->getRight();
	cur->setRight(tempNode);
      }
      else if(cur->getRight()->getLeft() != NULL && cur->getRight()->getRight() != NULL){
	Node* tempNode = cur->getRight()->getRight();
        while(tempNode->getLeft() != NULL) {
	  tempNode = tempNode->getLeft();
	}
	Node* tempNode2 = new Node();
	tempNode2->setInformation(tempNode->getInformation());
        remove(root, cur, tempNode->getInformation());
	tempNode2->setLeft(cur->getRight()->getLeft());
        tempNode2->setRight(cur->getRight()->getRight());
	cur->setRight(tempNode2);
      }
    }
  }
  
}

   
int hasChild(Node* node) {

  //if node has two children, return 0. If node has a child, return 1 or 2. If node has no children, return 3.
  if((node->getLeft() != NULL) && (node->getRight() != NULL) ) {
    return 0;
  }
  //has left
  else if((node->getLeft() != NULL) && (node->getRight() == NULL) ) {
    return 1;
  }
  //has right
  else if((node->getLeft() == NULL) && (node->getRight() != NULL) ) {
    return 2;
  }

  else {
    return 3;
  }
}
