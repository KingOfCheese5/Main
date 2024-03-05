#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include "Node.h"

int isMath(char c);

using namespace std;

int main() {

  char readInput[50];
  
  cout << "Enter a mathematical expression" << endl;
  cout << "The expression should be in infix form" << endl;
  cin.get(input, 81);
  cin.ignore(81, '\n');

  for(int i = 0; i < strlen(readInput); i++) {
    if(isdigit(readInput[i] == 0) {
	cout << "number" << endl;
      }
      else if(isMath[i] == 0) {
      	cout << "math" << endl;
      }
      else if(){
	cout << "who" << endl;
      }
      
      

  return 0;
}
int isMath(char c) {

  //test if character is mathematical expression
  if(c == '+') || (c == '-') || (c == '*' || (c == '/') || (c == '^') {
      return 0;
    }

    //1 = false
    else {
      return 1;
    }
}
