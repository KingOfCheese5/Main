#include <iostream>
#include "Media.h"
#include <cstring>

using namespace std;

//media class
Media::Media(){

  //Get title and year for all types of media
  cout << "Enter title of media: " << endl;
  cin >> title;
  cin.clear();
  cin.ignore(10000, '\n');

  cout << "Enter year media was released: " << endl;
  cin >> year;
  cin.clear();
  cin.ignore(10000, '\n');
}

//getter functions
char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}

void Media::getInformation(){
  return;
}
