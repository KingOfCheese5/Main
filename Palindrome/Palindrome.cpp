//Name: Levi Lao
//Last Edit: 9/13/23
//Project: Palindrome
//Purpose: Prompt is inputted. If prompt is palindrome, "Palindrome is printed"
//Else, user is told prompt is not a palindrome.

#include <iostream>
#include <cstring>
using namespace std;

//drivers code
int main() {

  //Initialize Arrays
  char arr[81];
  char arr2[81];
  char arr3[81];
  int palindrome = 0;
  int count = 0;

  //Input
  cout << "Input: " << endl;

  cin.get(arr, 81);
  cin.get();

  //Take in input, remove null, space, and punctuation
  for (int i = 0; i < strlen(arr); i++) {
    if (arr[i] != '\0' && arr[i] != ' '  && ispunct(arr[i]) == 0){
      // Make lowercase
      arr2[count] = tolower(arr[i]);
	count++;
      }
  } arr2[count] = '\0';

  
  //reset count
  count = 0;

  //Reverse arr2 and save into arr3
  for (int i = strlen(arr2); i > 0; i--) {
    arr3[count] = arr2[i - 1];
    count++;
  } arr3[count] = '\0';

  //Iterate through both arrays to check for different characters
  for(int i = strlen(arr3) - 1; i >= 0; i--) {
    if(arr3[i] != arr2[i]) {
      palindrome++;
    }
  }
  
  
  //Final check for Palindrome
  if(palindrome == 0) {
    cout << "Palindrome" << endl;
  }
  else {
    cout << "Not Palindrome" << endl;

  }
  
  return 0;
  
}
