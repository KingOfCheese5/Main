#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>


using namespace std;

class Node{
 public:
  //Constructor
  Node();
  Node(char);
  
  //get next node pointer
  Node* getNext();

  //set next pointer to node pointer
  void setNext(Node*);

  //get prev node pointer
  Node* getPrev();

  //set previous node to node pointer
  void setPrev(Node*);

  //get left child of tree
  Node* getLeft();

  //set left
  void setLeft(Node* newNode);

  //get right child
  Node* getRight();

  //set right
  void setRight(Node* newNode);

  //get char
  char getChar();

  //set char
  void setChar(char newc);
  
  ~Node();

  char c;
 protected:
  Node* prev;
  Node* next;
  char newChar;
  Node* left;
  Node* right;
};

#endif
