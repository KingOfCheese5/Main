#include <iostream>
#include <cstring>
#include <math.h> 
#include <fstream> 

using namespace std;

void add(int (&heapArray)[101], int &inputTotal);
void sortArray(int (&heapArray)[101], int value, int index);
void print(int (&heapArray)[101], int index, int level, int inputTotal);
void remove(int (&heapArray)[101], int value, int index, int &inputTotal);

int main() {

  bool running = true;
  char addCopy[] = "add";
  char printCopy[] = "print";
  char deleteCopy[] = "delete";
  char quitCopy[] = "quit";
  char clearCopy[] = "clear";
  
  char addl[4];
  char printl[6];
  char deletel[7];
  char quitl[5];
  char clearl[6];

  //initialize array with 0s
  int heapArray[101];
  for (int i = 0; i < 100; i++) {
    heapArray[i] = 0;
  }

  while(running == true) {
    
    int inputTotal = 0;
    int index;
    int level;

    srand(time(NULL));
    
    cout << endl;
    cout << "Enter add, print, delete or clear" << endl;
    cout << "To exit program, type quit" << endl;

    //copy over strings
    char input[81];
    strcpy(addl, addCopy);
    strcpy(printl, printCopy);
    strcpy(deletel, deleteCopy);
    strcpy(quitl, quitCopy);
    strcpy(clearl, clearCopy);

    cin.get(input, 81);
    cin.ignore(81, '\n');

    //add values
    if(strcmp(input, addl) == 0) {
      add(heapArray, inputTotal);
    }
    //print out values
    else if(strcmp(input, printl) == 0) {
      index = 1;
      level = 0;
      print(heapArray, index, level, inputTotal);
    }
    //remove parent root
    else if(strcmp(input, deletel) == 0) {
      cout << heapArray[1] << endl;
      heapArray[1] = heapArray[inputTotal];
      heapArray[inputTotal] = 0;
      inputTotal--;
      remove(heapArray, heapArray[1], 1, inputTotal);
      cout << "Root deleted" << endl << endl;
    }
    
    else if(strcmp(input, clearl) == 0) {
      cout << "Cleared" << endl;
    }
    
    //exit program
    else if(strcmp(input, quitl) == 0) {
      cout << "Exited" << endl;
      running = false;
    }
    
  }
  
  return 0;
}

void add (int (&heapArray)[101], int &inputTotal) {
  // Input through console
  bool inputMethodLoop = true;
  while (inputMethodLoop == true) {
    cout << "CONSOLE or FILE? (uppercase)" << endl;
    char input[10];
    cin.get(input, 10);
    cin.get();
    if (strcmp(input, "CONSOLE") == 0) {
      int inputNums;
      bool sizeCheck = true;
      while (sizeCheck == true) {
	cout << "How many numbers are you adding?" << endl;
	cin >> inputNums;
	cin.get();
	// Make sure the user doesn't exceed the maximum allowed numbers in the tree 
	if (inputTotal + inputNums > 100) {
	  cout << "There isn't enough space to add that many numbers!" << endl;
	}
	else {
	  sizeCheck = false;
	}
      }
      // Add the inputted numbers into an array
      for (int i = inputTotal; i < (inputTotal + inputNums); i++) {
	cin >> heapArray[i+1];
	cin.get();
	sortArray(heapArray, heapArray[i+1], i+1);
      }
      inputTotal+= inputNums;
      inputMethodLoop = false;
    }
    // Input through File
    else if (strcmp(input, "FILE") == 0) {
      int inputNums;
      bool sizeCheck = true;
      while (sizeCheck == true) {
	cout << "How many numbers are you adding?" << endl;
	cin >> inputNums;
	cin.get();
	// Make sure the user doesn't exceed the maximum allowed numbers in the tree
	if (inputTotal + inputNums > 100) {
	  cout << "There isn't enough space to add that many numbers!" << endl;
	}
	else {
	  sizeCheck = false;
	}
      }
      // Add to array through file
      ifstream numbers("testNumbers.txt");
      int oneNumber;
      for (int i = inputTotal; i < (inputTotal + inputNums); i++) {
	numbers >> heapArray[i+1];
	sortArray(heapArray, heapArray[i+1], i+1);
      }
      inputTotal+= inputNums;
      inputMethodLoop = false;
    }
    else {
      cout << "That is not one of the two options!" << endl << endl;
    }
  }
}
void sortArray(int (&heapArray)[101], int value, int index) {
  int parentIndex = floor(index/2);
  // If the child is larger than its parent, swap
  if (value > heapArray[parentIndex] && parentIndex != 0) {
    int temp = heapArray[parentIndex];
    heapArray[parentIndex] = value;
    heapArray[index] = temp;
    // Recursion
    sortArray(heapArray, value, parentIndex);
  }
}

void print(int (&heapArray)[101], int index, int level, int inputTotal) {
  if (inputTotal == 1) {
    cout << "The tree is empty!" << endl << endl;
  }
  // Go through the right side of tree, finding where the tree stops, and indenting appropriately
  else if (inputTotal != 1) {
    if ((index*2) + 1 < inputTotal) {
      print(heapArray, (index*2) + 1, level + 1, inputTotal);
    }
    // Indent values
    for (int i = 0; i < level; i++) {
      cout << '\t';
    }
    cout << heapArray[index] << endl;
    // Left side
    if ((index*2) < inputTotal) {
      print(heapArray, (index*2), level + 1,  inputTotal);
    }
  }
}

void remove(int (&heapArray)[101], int value, int index, int &inputTotal) {
  int temp;
  int swapTemp = value;
  // Check to see if the parent has any children or if it's a leaf
  if (heapArray[index*2] != 0 || heapArray[index*2+1] != 0) {
    // If both children are larger than parent, choose the larger child
    if (heapArray[index*2] > value && heapArray[index*2+1] > value) {
      if (heapArray[index*2] > heapArray[index*2+1]) {
	temp = 1;
      }
      else if (heapArray[index*2] < heapArray[index*2+1]) {
	temp = 2;
      }
      else {
	temp = 1;
      }
      // Left child was larger than right
      if (temp == 1) {
	heapArray[index] = heapArray[index*2];
	heapArray[index*2] = swapTemp;
	remove(heapArray, heapArray[index*2], index*2, inputTotal);
      }
      // Right child was larger than left
      else if (temp == 2) {
	heapArray[index] = heapArray[index*2+1];
	heapArray[index*2+1] = swapTemp;
	remove(heapArray, heapArray[index*2+1], index*2+1, inputTotal);
      }
    }
    // Swap with left child
    else if (heapArray[index*2] > value && heapArray[index*2+1] <= value) {
      heapArray[index] = heapArray[index*2];
      heapArray[index*2] = swapTemp;
      remove(heapArray, heapArray[index*2], index*2, inputTotal);  
    }
    // Swap with right child
    else if (heapArray[index*2+1] > value && heapArray[index*2] <= value) {
      heapArray[index] = heapArray[index*2+1];
      heapArray[index*2+1] = swapTemp;
      remove(heapArray, heapArray[index*2+1], index*2+1, inputTotal);
    }
  }
}
