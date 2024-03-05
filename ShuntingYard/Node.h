#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>


using namespace std;

class Node{
 public:
  //Constructor
  Node();
  
  //Get next node pointer
  Node* getNext();

  //Set next pointer to node pointer
  void setNext(Node*);

  ~Node();
  
 protected:

  Node* next;
  char newChar;
};

#endif
