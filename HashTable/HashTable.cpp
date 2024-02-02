//Levi Lao
//First save: 1/29/24
//Utilize previous linkedlist code, store students in a hash table using student data. Use chaining(linked list) to deal with collisions. If there are more
//than 3 collisions in a code, create a table and double the size of the tablet, then rehash. Additionally, make function to create a random student using
//students from a list of random names.  

#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include "Student.h"
#include "Node.h"

using namespace std;

//initialize functions
void add(Student* &student, vector<Student*>* &studentList, int size, Node** &hash);
void print(Node* head);
void remove(Node* &head, Node* curr, Node* prev, int ID);

int main() {

  //copy in function commands
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
  vector<Student*>* studentList;
  int size = 100;

  Node** hash = new Node* [100];
  for(int i = 0; i < 100; i++) {
    hash[i] = NULL;
  }
    
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

    cin.get(input, 81);
    cin.ignore(81, '\n');

    //if statements for commands
    //add student to list
    if(strcmp(input, addl) == 0) {
      Student* inputStudent = new Student();

      //set size to variable so it can be changed later
      int size = 100;
      
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

      studentList->push_back(inputStudent);
      
      add(inputStudent, studentList, size, hash);
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

    //exit program
    else if(strcmp(input, quitl) == 0) {
      cout << "Exited" << endl;
      running = false;
    }
    
  }
  
  return 0;
}

void add(Student* &student, vector<Student*>* &studentList, int size, Node** &hash) {

  //get index for student ID
  Node inputNode = Node(student);
  int addID = inputNode->getStudent()->getID();
  int index = addID % 100;

  //if index is open, set student
  if(hashTable[index] == NULL) {
    hashTable[index] = inputNode;
  }
  //if not, allow for up to 3 collisions
  else if(hashTable[index]->getNext() == NULL) {
    hashTable[index]->getNext() = inputNode;
  }
  else if(hashTable[index]->getNext()->getNext() == NULL) {
    hashTable[index]->getNext()->getNext() = inputNode;
  }
  //if collisions > 3, rehash
  else {
    cout << "idk how to rehash lmao" << endl;
  }
}

void print(vector<Student*>* studentList) {

  //empty list
  if(studentList[0] == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
  //print information
  vector<Student*>::iterator iter = studentList->begin();
  for(iter; iter < studentList->end(); iter++) {
    cout << (*iter)->getStudent()->getFirstName << " " <<  (*iter)->getStudent()->getLastName << endl;
    cout << "ID: " (*iter)->getStudent()->getID() << endl;
    cout << "GPA: " << fixed << setprecision(2) << (*iter)->getStudent()->getGPA() << endl;
    cout << endl;
  }
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
