#include <iostream>
#include "Media.h"
#include <cstring>

using namespace std;

//media class
Media::Media(){
  
  bool running = true;
  cout << "Enter title of media: " << endl;
  cin.clear();
  cin >> title;
  cin.ignore(10000, '\n');

  while(running = true){
    cout << "Enter year media was released: " << endl;
    cin.clear();
    cin >> year;
    if(year == 0){
      running = true;
      cout << "Could not read" << endl;
    }else{
      running = false;
    }
  }
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
