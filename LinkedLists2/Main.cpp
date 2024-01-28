//Name: Levi Lao
//Date: 1/22/24
//Project: Utilize linked lists to alter student lists, being able to add, delete, print, and average the values of the students

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

//initialize functions
void add(Node* &head, Node* curr, Node* prev, Node* inputNode);
void print(Node* head);
void remove(Node* &head, Node* curr, Node* prev, int ID);
void average(Node* head, int total, float averageTotal);

int main() {

  //copy in function commands
  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char deleteCopy[] = "delete";
  char quitCopy[] = "quit";
  char averageCopy[] = "average";

  char addl[4];
  char printl[6];
  char deletel[7];
  char quitl[5];
  char average1[8];

  Node* head = NULL;
  Node* cur;
  Node* prev;
  
  while(running == true) {
    
    cout << endl;
    cout << "Enter add, print, delete, or average to alter the student list" << endl;
    cout << "If not, enter quit to exit program" << endl;

    //copy over strings
    char input[81];
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(deletel, deleteCopy);
    strcpy(quitl, quitCopy);
    strcpy(average1, averageCopy);

    cin.get(input, 81);
    cin.ignore(81, '\n');

    //if statements for commands
    //add student to list
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
    //print out all students
    else if(strcmp(input, printl) == 0) {
      print(head);
    }
    //take in ID and delete student
    else if(strcmp(input, deletel) == 0) {
      cout << "Enter the ID of the student you want to delete" << endl;
      int studentID;
      cin >> studentID;
      cin.get();

      remove(head, head, head, studentID);
    }
    //take averages of all the elements
    else if(strcmp(input, average1) == 0) {
      int totalElements = 0;
      float toAverage;
      average(head, totalElements, toAverage);
    }

    //exit program
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
     //recursion element
     else {
       add(head, curr->getNext(), curr, inputNode);
     }
     return;
  }
  return;
}

void print(Node* head) {

  //empty list
  if(head == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
  //print out the information of the head node.
  cout << head->getStudent()->firstName << " " << head->getStudent()->lastName;
  cout << ", " << head->getStudent()->getID() << ", " << fixed << setprecision(2) << head->getStudent()->getGPA() << endl;

  //recursion element
  if(head->getNext() != NULL){
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
  //can't find student
  if(curr == NULL) {
    cout << "Could not find student" << endl;
    return;
  }
  if(curr->getStudent()->getID() == ID) {
    cout << "debug" << endl;
    
    //if head is only component, check that list is empty
    if(head->getStudent()->getID() == ID && head->getNext() == NULL) {
      head->~Node();
      head = NULL;
      return;
    }

    //if head needs to be deleted
    else if(curr == head) {
      Node* tempNode = head->getNext();
      head->~Node();
      head = tempNode;
      cout << "debug3" << endl;
      
    }
    // Alter getNext of the deleted node
    else if (curr != head && curr->getNext() != NULL) {
      Node* tempNode2 = curr->getNext();
      prev->setNext(tempNode2);
      curr->~Node();
    }
    //Deleted node has no next 
    else if (curr != head && curr->getNext() == NULL) {
      Node* nullNode = NULL;
      prev->setNext(nullNode);
      curr->~Node();
    }
  }
  //recursion element
  else {
    remove(head, curr->getNext(), curr, ID);
  }    
}

void average(Node* head, int total, float averageTotal) {

  //if list is empty
  if(head == NULL && total == 0) {
    cout << "There are no elements to average" << endl;
  }
  //add to total and call average() again
  else if(head != NULL){
    averageTotal = averageTotal + head->getStudent()->getGPA();
    total = total + 1;
    average(head->getNext(), total, averageTotal);
  }
  else {
    //print
    cout << "Average: " << fixed << setprecision(2) << (averageTotal/total) << endl;
  }
}

