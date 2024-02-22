#include <iostream>
#include <cstring>

using namespace std;

int main() {

  bool running = true;;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char deleteCopy[] = "delete";
  char quitCopy[] = "quit";
  char clearCopy[] = "clear";
  
  char addl[4];
  char printl[6];
  char deletel[7];
  char quitl[5];
  char clear1[5];

    //main
  while(running == true) {
    
    cout << endl;
    cout << "Enter add, print, delete or clear to sort " << endl;
    cout << "To exit program, type quit" << endl;

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
    if(strcmp(input, addl) == 0) {
      cout << ""
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
[I    //generate random students
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
