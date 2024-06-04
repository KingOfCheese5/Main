//Name: Levi Lao
//Date: 6/4/24
//Project: RBT Deletion, use previous RBT framework and allow for nodes to be deleted and searched for

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
void remove(Node* &root, Node* cur, int data);
void doubleBlack(Node* &root, Node* cur);
void search(int number, Node* node);

int main() {

  //create variables
  Node* root = NULL;
  char input[81];
  
  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char removeCopy[] = "remove";
  char quitCopy[] = "quit";
  char searchCopy[] = "search";
  
  char addl[4];
  char printl[6];
  char removel[7];
  char quitl[5];
  char searchl[7];

  cout << "RBT: Insertion" << endl;

  while(running == true) {

    cout << "Enter add, print, remove, or quit" << endl;
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(removel, removeCopy);
    strcpy(searchl, searchCopy);
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

    if(strcmp(input, removel) == 0) {
      cout << "Enter value to be deleted: " << endl;
      int number;
      cin >> number;
      cin.get();
      remove(root, root, number);
    }
    if(strcmp(input, searchl) == 0) {
      cout << "Enter value to be searched" << endl;
      int number;
      cin >> number;
      cin.get();
      search(number, root);
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
  else if(data < cur->getData()){
    if(cur->getLeft() == NULL){
      cur->setLeft(node);
      node->setParent(cur);
      balance(root, node);
    }
    else{
      add(root, cur->getLeft(), node, data);
    }
  }

  //make right subtree
  else if(data >= cur->getData()){
    if(cur->getRight() == NULL){
      cur->setRight(node);
      node->setParent(cur);
      balance(root, node);
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

//balance after every addition
void balance(Node* &root, Node* node) {
    Node* parent = NULL;
    Node* grandparent = NULL;

    // Cases 1 and 2, root exists and parent is black
    while ((node != root) && (node->getColor() == 1) && (node->getParent()->getColor() == 1)) {
        parent = node->getParent();
        grandparent = parent->getParent();

        // Parent is the left child of grandparent
        if (parent == grandparent->getLeft()) {
            Node* uncle = grandparent->getRight();

            // Case 3: Red uncle, left child
            if (uncle != NULL && uncle->getColor() == 1) {
                grandparent->setColor(1);  
                parent->setColor(0);       
                uncle->setColor(0);        
                node = grandparent;        
            } else {
                // Case 4: left/right, rotate left
                if (node == parent->getRight()) {
                    leftRotate(root, parent);
                    node = parent;
                    parent = node->getParent();
                }
                // Case 5: left/left, rotate right
                rightRotate(root, grandparent);
                parent->setColor(0);         
                grandparent->setColor(1);    
                node = parent;               
            }
        } else {  //right parent
            Node* uncle = grandparent->getLeft();

            // Case 3: Red uncle
            if (uncle != NULL && uncle->getColor() == 1) {
                grandparent->setColor(1);  
                parent->setColor(0);       
                uncle->setColor(0);        
                node = grandparent;        
            } else {
                // Case 4: Right/left, left child
                if (node == parent->getLeft()) {
                    rightRotate(root, parent);
                    node = parent;
                    parent = node->getParent();
                }
                // Case 5: Right/right, right child
                leftRotate(root, grandparent);
                parent->setColor(0);         
                grandparent->setColor(1);    
                node = parent;               
            }
        }
    }
    root->setColor(0);  //black root
}

void remove(Node* &root, Node* cur, int data) {
  //recursive test case
  if (root == NULL) {
    cout << "Empty tree" << endl;
    return;
  }
  else {
    //recurse right
    if (cur->getData() < data) {
      remove(root, cur->getRight(), data);
    }
    //recurse left
    else if (cur->getData() > data) {
      remove(root, cur->getLeft(), data);
    }
    //value found
    else {
      //make sure no children
      if (cur->getLeft() == NULL && cur->getRight() == NULL) {
	//call double black function
	if (cur->getColor() == 0) {
	  doubleBlack(root, cur);
	}
	//balance parents
	//left side
	if (cur->getParent()->getLeft() == cur) {
	  cur->getParent()->setLeft(NULL);
	}
	else {
	  //right side
	  cur->getParent()->setRight(NULL);
	}
	cur = NULL;
      }
      //if deleted node has two children
      else if (cur->getLeft() != NULL && cur->getRight() != NULL) {
	//replacement node
	Node* replace= cur->getRight();
	while (replace->getLeft() != NULL) {
	  replace = replace->getLeft();
	}
	cur->setData(replace->getData());
	remove(root, replace, replace->getData()); 
      }
      // One child
      else {
	// Deleted node is red
	if (cur->getColor() == 1) {
	  if (cur->getLeft() != NULL) {
	    cur->setData(cur->getLeft()->getData());
	    cur->setLeft(NULL);
	  }
	  else {
	    cur->setData(cur->getRight()->getData());
	    cur->setRight(NULL);
	  }
	  cur->setColor(0);
	}
	// Child is red
	else if ((cur->getLeft() != NULL && cur->getLeft()->getColor() == 1) || (cur->getRight() != NULL && cur->getRight()->getColor() == 1)) {
	  if (cur->getLeft() != NULL) {
            cur->setData(cur->getLeft()->getData());
            cur->setLeft(NULL);
          }
          else {
            cur->setData(cur->getRight()->getData());
            cur->setRight(NULL);
          }

	}
	// Double black
	else {
	  if (cur->getLeft() != NULL) {
            cur->setData(cur->getLeft()->getData());
            cur->setLeft(NULL);
          }
          else {
            cur->setData(cur->getRight()->getData());
            cur->setRight(NULL);
          }

	  doubleBlack(root, cur);
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

void doubleBlack(Node* &root, Node* cur) {
    //case 1: node = root
    if (cur == root) {
        cur->setColor('B');
        return;
    }

    Node* sibling = cur->getSibling();
    Node* parent = cur->getParent();

    //case 2: red sibling
    if (sibling != NULL && sibling->getColor() == 1) {
      parent->setColor(1);
        sibling->setColor(0);
        if (cur == parent->getLeft()) {
            leftRotate(root, parent);
        } else {
            rightRotate(root, parent);
        }
        // Continue handling the double black
        doubleBlack(root, cur);
    }
    //black sibling
        //case 3: black parent, sibling, and children
    else if (parent->getColor() == 0 && sibling != NULL && (sibling->getColor() == 0) && (sibling->getLeft() == NULL || sibling->getLeft()->getColor() == 0) && (sibling->getRight() == NULL || sibling->getRight()->getColor() == 0)) {
      sibling->setColor(1);
      doubleBlack(root, parent);
    }
    //case 4: red parent, black sibling
      else if (parent->getColor() == 1 && sibling != NULL && sibling->getColor() == 0 && (sibling->getLeft() == NULL || sibling->getLeft()->getColor() == 0) && (sibling->getRight() == NULL || sibling->getRight()->getColor() == 0)) {
	parent->setColor(0);
        sibling->setColor(1);
      }
        // Case 5 & 6: Sibling's inner child is red
        else if (sibling != NULL) {
            if ((cur == parent->getLeft() && sibling->getRight() != NULL && sibling->getRight()->getColor() == 1) ||
                (cur == parent->getRight() && sibling->getLeft() != NULL && sibling->getLeft()->getColor() == 1)) {
                if (cur == parent->getLeft()) {
                    rightRotate(root, sibling);
                } else {
                    leftRotate(root, sibling);
                }
                sibling->setColor(1);
                if (cur == parent->getLeft()) {
                    sibling->getRight()->setColor(0);
                } else {
                    sibling->getLeft()->setColor(0);
                }
                // Continue handling the double black
                doubleBlack(root, cur);
            }
            // Case 6: Sibling's outer child is red
            else {
                if (cur == parent->getLeft()) {
                    sibling->getRight()->setColor(sibling->getColor());
                } else {
                    sibling->getLeft()->setColor(sibling->getColor());
                }
                sibling->setColor(parent->getColor());
                parent->setColor(0);
                if (cur == parent->getLeft()) {
                    leftRotate(root, parent);
                } else {
                    rightRotate(root, parent);
                }
                if (cur == parent->getLeft()) {
                    sibling->getRight()->setColor(0);
                } else {
                    sibling->getLeft()->setColor(0);
                }
            }
        }

}

//recurse through tree
void search(int number, Node* node) {
  //will be tested on root
  if(node == NULL) {
    return;
  }
  else {
    //go left if value is smaller
    if(node->getData() > number) {
      search(number, node->getLeft());
    }
    //go right if value is larger
    else if(node->getData() < number) {
      search(number, node->getRight());
    }
    //print if found
    else if(node->getData() == number){
      cout << "value found" << endl;
      return;
    }
    else {
      cout << "value does not exist" << endl;
      return;
    }
  }

}
