#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Node* &head, Node* curr, Node* prev, Node* inputNode);
void print(Node* head);
void remove(Node* &head, Node* curr, Node* prev, int ID);

int main() {

  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char deleteCopy[] = "delete";
  char quitCopy[] = "quit";

  char addl[4];
  char printl[6];
  char deletel[7];
  char quitl[5];

  Node* head = NULL;
  Node* cur;
  Node* prev;
  
  while(running == true) {
    
    cout << endl;
    cout << "Enter add, print, or delete to alter the student list" << endl;
    cout << "If not, enter quit to exit program" << endl;

    //copy over strings
    char input[81];
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(deletel, deleteCopy);
    strcpy(quitl, quitCopy);
  
    cin.get(input, 81);
    cin.ignore(81, '\n');

    //if statements for commands
    if(strcmp(input, addl) == 0) {
      Student* inputStudent = new Student();

      cout << "First Name: " << endl;
      char input[20];
      cin.get(input, 20);
      cin.get();
      strcpy(inputStudent->getFirstName(), input);
      
      cout << "Last Name: " << endl;
      cin.get(input, 20);
      cin.get();
      strcpy(inputStudent->getLastName(), input);
      
      cout << "Student ID: " << endl;
      int int1;
      cin >> int1;
      cin.get();
      inputStudent->setID(int1);
      
      cout << "Student GPA: " << endl;
      float float1;
      cin >> float1;
      cin.get();
      inputStudent->setGPA(float1);

      Node* inputNode = new Node(inputStudent);
      
      add(head, head, head, inputNode);
    }
    
    else if(strcmp(input, printl) == 0) {
      print(head);
    }
    else if(strcmp(input, deletel) == 0) {
      cout << "delete" << endl;
    }
    else if(strcmp(input, quitl) == 0) {
      cout << "Exited" << endl;
      running = false;
    }
    
  }
  
  return 0;
}

void add(Node* &head, Node* curr, Node* prev, Node* inputNode) {

  //set new head
  if(head == NULL) {
    head = inputNode;
    cout << "added head" << endl;
  }
  else {
    //if input is smaller than head, place in front of head
     if(inputNode->getStudent()->getID() < head->getStudent()->getID()) {
       Node* tempNode = head;
       head = inputNode;
       head->setNext(tempNode);
     }
     //place input in between two nodes
     else if(inputNode->getStudent()->getID() < curr->getStudent()->getID()) {
       prev->setNext(inputNode);
       inputNode->setNext(curr);
     }
     //end list
     else if(curr->getNext() == NULL) {
       curr->setNext(inputNode);
     }
     else {
       add(head, curr->getNext(), curr, inputNode);
     }
     return;
  }
  return;
}

void print(Node* head) {

  if(head == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
  //print out the information of the head node.
  cout << head->getStudent()->firstName << " " << head->getStudent()->lastName;
  cout << ", " << head->getStudent()->getID() << ", " << fixed << setprecision(2) << head->getStudent()->getGPA() << endl;

  //cout << head->getNext()->firstName << " " << head->getNext()->lastName;
  //cout << ", " << head->getNext()->getID() << ", " << fixed << setprecision(2) << head->getNext()->getGPA() << endl;
  
  if(head->getNext() != NULL){
    cout << "Next found" << endl;
    print(head->getNext());
  }
  return;
}

void remove(Node* &head, Node* curr, Node* prev, int ID) {

  //List is empty
  if(head == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
  if(curr = NULL) {
    cout << "Could not find student" << endl;
    return;
  }
  if(curr->getStudent->getID == ID) {

    if(head->getID == ID) {
      head->~Node();
      head = NULL;
      return;
    }

    else if(curr = head) {
      Node* tempNode = head->getNext();
      head->~Node();
      head = tempNode;
      
    }
    
  }

}
