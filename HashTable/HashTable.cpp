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
void add(Student* &student, vector<Student*>* &studentList, int size, int newsize, Node** &hash);
void print(vector<Student*>* studentList);
void remove(vector<Student*>* studentList, int id);
void rehash(Node** &hash, int &size, int oldSize);
void addHash(Node** &hash, Node* &node, int newIndex, int size);

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
  int newSize = 100;

  Node** hash = new Node* [100];
  for(int i = 0; i < 100; i++) {
    hash[i] = NULL;
  }
    
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
      
      add(inputStudent, studentList, size, newSize, hash);
    }
    //print out all students
    else if(strcmp(input, printl) == 0) {
      print(studentList);
    }
    //take in ID and delete student
    else if(strcmp(input, deletel) == 0) {
      cout << "Enter the ID of the student you want to delete" << endl;
      int studentID;
      cin >> studentID;
      cin.get();

      remove(studentList, studentID);
    }

    //exit program
    else if(strcmp(input, quitl) == 0) {
      cout << "Exited" << endl;
      running = false;
    }
    
  }
  
  return 0;
}

void add(Student* &student, vector<Student*>* &studentList, int size, int newsize, Node** &hash) {

  //get index for student ID
  Node* inputNode = new Node(student);
  int addID = inputNode->getStudent()->getID();
  int index = addID % size;

  //if index is open, set student
  if(hash[index] == NULL) {
    hash[index] = inputNode;
  }
  //if not, allow for up to 3 collisions
  else if(hash[index]->getNext() == NULL) {
    hash[index]->getNext()->setNext(inputNode);
  }
  else if(hash[index]->getNext()->getNext() == NULL) {
    hash[index]->getNext()->getNext()->setNext(inputNode);
  }
  //if collisions > 3, rehash
  else {
    rehash(hash, newsize, size);
  }
}

void print(vector<Student*>* studentList) {

  cout << endl;
  
  //empty list
  if(studentList->at(0) == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
  //print information
  vector<Student*>::iterator iter = studentList->begin();
  for(iter; iter < studentList->end(); iter++) {
    cout << (*iter)->getFirstName() << " " <<  (*iter)->getLastName() << endl;
    cout << "ID: " << (*iter)->getID() << endl;
    cout << "GPA: " << fixed << setprecision(2) << (*iter)->getGPA() << endl;
    cout << endl;
  }
}

void remove(vector<Student*>* studentList, int id) {

  cout << endl;
  
  //empty list
  if(studentList->at(0) == NULL) {
    cout << "The list is empty" << endl;
    return;
  }
  //iterate through list and delete ID
  vector<Student*>::iterator iter = studentList->begin();
  for(iter; iter < studentList->end(); iter++) {
    if((*iter)->getID() == id) {
      studentList->erase(iter);
    }
  }
  cout << "student eviscerated" << endl;
}

void rehash(Node** &hash, int &size, int oldSize) {
  
  Node** tempHash = new Node*[oldSize];
  for (int i = 0; i < size; i++) {
    tempHash[i] = hash[i];
  }

  size = size * 2;
  Node** newHash = new Node* [size];
  for(int x = 0; x < size; x++) {
    newHash[x] = NULL;
  }

  for(int i = 0; i < size; i++) {
    if(tempHash[i] != NULL) {
      int index1 = (tempHash[i]->getStudent()->getID())%size;
      Node* moveHash1 = tempHash[i];
       if (tempHash[i]->getNext() != NULL) {
	 int index2 = (tempHash[i]->getNext()->getStudent()->getID())%size;
	  Node* moveHash2 = tempHash[i]->getNext();
	  if(tempHash[i]->getNext()->getNext() != NULL) {
	    int index3 = (tempHash[i]->getNext()->getNext()->getStudent()->getID())%size;
	    Node* moveHash3 = tempHash[i]->getNext()->getNext();
	     //Make sure nothing else is after node
	     moveHash3->setNext(NULL);
	     addHash(newHash, moveHash3, index3, size);
	  }
	  moveHash2->setNext(NULL);
          addHash(newHash, moveHash2, index2, size);
       }
       moveHash1->setNext(NULL);
       addHash(newHash, moveHash1, index1, size);
    }
    
  }
  delete[] hash;
  //old table becomes new table
  hash = newHash;
}

void addHash(Node** &hash, Node* &node, int newIndex, int size) {
  if (hash[newIndex] == NULL) {
    hash[newIndex] = node;
  }
  else if (hash[newIndex]->getNext() == NULL) {
    hash[newIndex]->setNext(node);
  }
  else if (hash[newIndex]->getNext()->getNext() == NULL) {
    hash[newIndex]->getNext()->setNext(node);
  }
  else {
    rehash(hash, size, size);
  }
}
