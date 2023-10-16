//Name: Levi Lao
//Last Save: 10/11/23
//Code: Create a vector of pointers that allows for pointers to be added,
//and removed. Use example of reading in students.  


#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include <iomanip>

//initialize varaibles
using namespace std;
bool running = true;;
char addCopy[] = "add";
char printCopy[] = "print";
char obliterateCopy[] = "obliterate";
char quitCopy[] = "quit";

//l added after each as to not interefere with function names
char addl[4];
char printl[6];
char obliteratel[11];
char quitl[5];

//initialize struct and functions
struct Student {
  char first[81];
  char last[81];
  int studentID = 0;
  float GPA = 0;
};

void add(vector<Student*>*StudentList);
void print(vector<Student*>*StudentList);
void obliterate(vector<Student*>*StudentList);
  

int main() {

  //Prompt and enter while loop
  vector<Student*>* StudentList = new vector<Student*>();
  cout << "Enter add, print, or obliterate to alter the student list" << endl;
  cout << "If not, enter quit to exit program" << endl;
  while(running == true) {

    //copy over strings
    char input[81];
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(obliteratel, obliterateCopy);
    strcpy(quitl, quitCopy);
  
    cin.get(input, 81);
    cin.ignore(81, '\n');

    //if statements for commands
    if(strcmp(input, addl) == 0) {
      add(StudentList);
    }
    else if(strcmp(input, printl) == 0) {
      print(StudentList);
    }
    else if(strcmp(input, obliteratel) == 0) {
      obliterate(StudentList);
    }
    else if(strcmp(input, quitl) == 0) {
      cout << "Exited" << endl;
      running = false;
    }
    
  }
  return 0;
}

//Add student to vector
void add(vector<Student*>*vect) {
  
  char inputFirst[81];
  char inputLast[81];
  int inputID = 0;
  float inputGPA = 0;

  cout << "First Name: " << endl;
  cin >> inputFirst;
  cout << "Last Name: " << endl;
  cin >> inputLast;
  cout << "Student ID: " << endl;
  cin >> inputID;
  cout << "Student GPA: " << endl;
  cin >> inputGPA;

  cin.ignore(81, '\n');
  
  //Helped by Ethan K.
  //Copy information into student structure
  Student* student = new Student();
  strcpy(student->first, inputFirst);
  strcpy(student->last, inputLast);
  student->studentID = inputID;
  student->GPA = inputGPA;
  vect->push_back(student);

  cout << "Student Saved" << endl;
  cout << endl;
}


void print(vector<Student*>*vect) {

  cout << "Student List: " << endl;

  //Iterate through vector
  //Code helped by educative.io
  //https://www.educative.io/answers/how-to-iterate-through-a-vector-in-cpp
  
  vector<Student*>::iterator iter = vect->begin();

  for (iter; iter < vect->end(); iter++) {
    cout << (*iter)->first << " "
         << (*iter)->last << ", "
         << (*iter)->studentID << ", "
         << fixed << setprecision(2) << (*iter)->GPA << endl;
  }
  cout << " " << endl;
  
}

void obliterate(vector<Student*>*vect) {

  //Enter ID and search for it in vector list
  int idcompare = 0;
  
  cout << "Enter the ID of the student you would like to delete" << endl;
  cin >> idcompare;

  //Set up iterator again
  vector<Student*>::iterator iter = vect->begin();

   for (iter; iter < vect->end(); iter++) {

     //remove student and break loop
     if (idcompare == (*iter)->studentID) {
       delete *iter;
       vect->erase(iter);
       break;
     }
   }

   cout << "Student obliterated" << endl;
   cin.ignore(81, '\n');
   cout << " " << endl;
}
