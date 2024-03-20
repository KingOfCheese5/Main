#include <iostream>
#include <string>
#include <cstring>
#include "Node.h"
#include <vector>
#include <fstream>
using namespace std;

void add(Node* root, Node* cur, Node* node);
void print(Node* cur, int count);
int search(Node* cur, int value);


int main() {

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
      else if(strcmp(input, "file") == 0) {
	//just use hashtable code
	/*vector<int> numbers;
	fstream stream1;; 

	stream1.open("numbers.txt");
	for(int i = 0; i<= 20; i++) {
	  char temp;
	  stream1.getline(temp, 15);
	  int tempInt = stoi(temp);
	  numbers.push_back(tempInt);
	}
	stream1.close(); */
	cout << "yuh" << endl;
      }
    }
    
    if(strcmp(input, printl) == 0) {
      cout << "printed" << endl;
    }

    if(strcmp(input, deletel) == 0) {
      cout << "deleted" << endl;
    }

    if(strcmp(input, searchl) == 0) {
      cout << "searched" << endl;
    }

    if(strcmp(input, quitl) == 0) {
      cout << "Program exited" << endl;
      running = false;
    }
  }
}

void add(Node* root, Node* cur, Node* node) {
  cout << "54 from treball is odee shooting hangpulls" << endl;

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

void print(Node* cur, int count){
    if(cur->getLeft() != NULL){
        print(cur->getLeft(), count + 1);
    }
    for(int i = 0; i < count; i++){
        cout << '\t';
    }
    cout << cur->getInformation() << endl;
    if(cur->getRight() != NULL){
        print(cur->getRight(), count + 1);
    }

}

int search(Node* cur, int value){
    if(value > cur->getInformation()){
        if(cur->getRight() != NULL){
            return search(cur->getRight(), value);
        }
    }
    else if(value < cur->getInformation()){
        if(cur->getLeft() != NULL){
            return search(cur->getLeft(), value);
        }
    }
    else if(value == cur->getInformation()){
        return 1;
    }
    return 0;
}
