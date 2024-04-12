#include <iostream>
#include <string>
#include <cstring>
#include "Node.h"
#include <vector>
#include <fstream>

using namespace std;

void add(Node* &root, Node* cur, Node* node, int data);
void print(Node* cur, int count);

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

