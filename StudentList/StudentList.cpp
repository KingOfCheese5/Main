#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;
bool running = true;;
char addCopy[] = "add";
char printCopy[] = "print";
char obliterateCopy[] = "obliterate";
char quitCopy[] = "quit";

char add[4];
char print[6];
char obliterate[11];
char quit[5];


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

  vector<Student*>* StudentList = new vector<Student*>();
  cout << "Enter add, print, or obliterate to alter the student list" << endl;
  cout << "If not, enter quit to exit program" << endl;
  while(running == true) {
      
    char input[81];
    strcpy(add, addCopy);
    strcpy(print, printCopy);
    strcpy(obliterate, obliterateCopy);
    strcpy(quit, quitCopy);
  
    cin.get(input, 81);
    cin.ignore(81, '\n');
    
    if(strcmp(input, add) == 0) {
      add(StudentList);
    }
    else if(strcmp(input, print) == 0) {
      cout << "printed" << endl;
    }
    else if(strcmp(input, obliterate) == 0) {
      cout << "obliterated" << endl;
    }
    else if(strcmp(input, quit) == 0) {
      cout << "exited" << endl;
      running = false;
    }
    else {
      cout << "Enter Again" << endl;
    }
    
  }
  return 0;
}

void add(vector<Student*>*StudentList) {

}
