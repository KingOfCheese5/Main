#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

Media::Media() {
  description = new char[80];
  id = 0;
}

Media::Media(char* newdescription) {
  description = new char[80];
  strcpy(description, newdescription);
  id = 0;
}

char* Media::getDescription() {
  return description;
}

int Media::getID() {
  return id;
}
