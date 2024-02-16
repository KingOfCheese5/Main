//Levi Lao
//Final save: 2/15/24
//Utilize previous linkedlist code, store students in a hash table using student data. Use chaining(linked list) to deal with collisions. If there are more
//than 3 collisions in a code, create a table and double the size of the tablet, then rehash. Additionally, make function to create a random student using
//students from a list of random names.
//Credit: Vikram & Roger helped with rehash, tutorialspoint helped with reading in txt file "https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm"

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <vector>
#include "Student.h"
#include "Node.h"

using namespace std;

//initialize functions
void add(Student* &student, vector<Student*>* &studentList, int size, int newsize, Node** &hash);
void print(vector<Student*>* studentList);
void remove(vector<Student*>* studentList, int id);
void rehash(Node** &hash, int &size, int oldSize, bool &rehashing);
void addHash(Node** &hash, Node* &node, int newIndex, int size, bool &rehashing);
void createRandom(vector<Student*>* &studentList, vector<char*> first, vector<char*> last, int people, int size, int newSize, Node** &hash);

int main() {

  vector<char*> firstNames;
  vector<char*> lastNames;
  
  fstream stream1;
  fstream stream2;

  //Get names from txt files and push into vector
  stream1.open("firstNames.txt");
  for(int i = 0; i<= 20; i++) {
    char* temp1 = new char [15];
    stream1.getline(temp1, 15);
    firstNames.push_back(temp1);
  }
  stream1.close();

  stream2.open("lastNames.txt");
  for(int i = 0; i<= 20; i++) {
    char* temp = new char [15];
    stream2.getline(temp, 15);
    lastNames.push_back(temp);
  }
  stream2.close();

  //copy in function commands
  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char deleteCopy[] = "delete";
  char quitCopy[] = "quit";
  char randomCopy[] = "random";
  
  char addl[4];
  char printl[6];
  char deletel[7];
  char quitl[5];
  char random1[7];

  Node* head = NULL;
  vector<Student*>* studentList = new vector<Student*>();
  int size = 100;
  int newSize = 100;

  Node** hash = new Node* [100];
  for(int i = 0; i < 100; i++) {
    hash[i] = NULL;
  }

  //main
  while(running == true) {
    
    cout << endl;
    cout << "Enter add, print, or delete to alter the student list" << endl;
    cout << "Or enter random to generate a list of random students" << endl;
    cout << "If not, enter quit to exit program" << endl;

    //copy over strings
    char input[81];
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(deletel, deleteCopy);
    strcpy(quitl, quitCopy);
    strcpy(random1, randomCopy);

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
    //generate random students
    else if(strcmp(input, random1) == 0) {
      cout << "How many students would you like to generate?" << endl;
      int people;
      cin >> people;
      cin.get();

      createRandom(studentList, firstNames, lastNames, people, size, newSize, hash);
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
    hash[index]->setNext(inputNode);
  }
  else if(hash[index]->getNext()->getNext() == NULL) {
    hash[index]->getNext()->setNext(inputNode);
  }
  //if collisions > 3, rehash
  else {
    bool rehashing = true;
    hash[index]->getNext()->getNext()->setNext(inputNode);
    while(rehashing == true) {
      rehash(hash, newsize, size, rehashing);
    }
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
    cout << "First: " << (*iter)->getFirstName() << endl;
    cout << "Last: " << (*iter)->getLastName() << endl;
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
  //student deleted
  cout << "student eviscerated" << endl;
}

void rehash(Node** &hash, int &size, int oldSize, bool &rehashing) {

  //set bool to false then create new hashtable
  rehashing = false;
  size = size * 2;
  Node** newHash = new Node* [size];
  //make every space null
  for(int x = 0; x < size; x++) {
    newHash[x] = NULL;
  }

  //Rehash, placing each node into corresponding index on new table
  for(int i = 0; i < size/2; i++) {
    if(hash[i] != NULL) {
      int index1 = (hash[i]->getStudent()->getID())%size;
      Node* moveHash1 = hash[i];
       if (hash[i]->getNext() != NULL) {
	 int index2 = (hash[i]->getNext()->getStudent()->getID())%size;
	  Node* moveHash2 = hash[i]->getNext();
	  if(hash[i]->getNext()->getNext() != NULL) {
	    int index3 = (hash[i]->getNext()->getNext()->getStudent()->getID())%size;
	    Node* moveHash3 = hash[i]->getNext()->getNext();
	     //Make sure nothing else is after node
	     moveHash3->setNext(NULL);
	     addHash(newHash, moveHash3, index3, size, rehashing);
	  }
	  moveHash2->setNext(NULL);
          addHash(newHash, moveHash2, index2, size, rehashing);
       }
       moveHash1->setNext(NULL);
       addHash(newHash, moveHash1, index1, size, rehashing);
    }
    
  }
  delete[] hash;
  //old table becomes new table
  hash = newHash;
}

//function to actually add new indices to hash table
void addHash(Node** &hash, Node* &node, int newIndex, int size, bool &rehashing) {
  //pretty much the same code from add()
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
    rehash(hash, size, size, rehashing);
  }
}

void createRandom(vector<Student*>* &studentList, vector<char*> first, vector<char*> last, int people, int size, int newSize, Node** &hash){
  //set seed
  srand(time(NULL));
  int ID = 100000;
  
  //randomly generate a name and a gpa
  for(int i = 0; i < people; i++){
    //get random number from 1-20
    int randomFirst = rand()%20;
    int randomLast = rand()%20;

    //calculate a gpa
    float GPA = (float)(rand()%(100) + 1)/25;

    //create the student and add it to the list
    Student* inputStudent = new Student();

    strcpy(inputStudent->getFirstName(), first.at(randomFirst));
    strcpy(inputStudent->getLastName(), last.at(randomLast));
    inputStudent->setID(ID);
    inputStudent->setGPA(GPA);
    
    studentList->push_back(inputStudent);
    add(inputStudent, studentList, size, newSize, hash);

    ID++;
  }
  return;
}
