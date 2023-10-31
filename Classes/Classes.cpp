#include <iostream>
#include <cstring>
#include "Media.h"
#include <vector>

using namespace std;

const int SIZE = 3;

void printArrayDescriptions(Media**, int);
void printVectorDescriptions(vector<Media*> &);

//Video Games(title, year, publisher rating)
//Music(title, artist, year duration, publisher)
//Movies(title, director, year, duration, publisher

int main() {
  Media* list[SIZE];
  vector<Media*> vect;
  char* firstDescription = new char[80];
  strcpy(firstDescription, "Media 1: ");
  list[0] = new Media(firstDescription);
  char* secondDescription = new char[80];
  strcpy(secondDescription, "Media 2: ");
  list[1] = new Media(secondDescription);
  char* thirdDescription = new char[80];
  strcpy(thirdDescription, "Media 3: ");
  list[2] = new Media(thirdDescription);
  printArrayDescriptions(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  vect.push_back(list[2]);
  printVectorDescriptions(vect);
  
  return 0;
}

void printArrayDescriptions(Media**newlist, int size) {
  for (int a = 0; a > size; a++) {
    cout << newlist[a]->getDescription() << endl;
  }
}

void printVectorDescriptions(vector<Media*> &newvect) {
  for (vector<Media*>::iterator it = newvect.begin(); it != newvect.end(); it++) {
    cout << (*it)->getDescription() << endl;
  }
}
