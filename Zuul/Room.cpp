#include <iostream>
#include <cstring>
#include "Room.h"
#include <map>

using namespace std;

//room function
room::room() {

}

//getters and setters
char*room::getDescription() {
  return description;
}

void room::setRoomID(int x) {
  roomID = x;
}

void room::setExit(char* dir, room* r) {
  exits.insert(pair<char*, room*>(dir, r));
}

//iterate through to return room pointer
room* room::getExit(char* input) {
  for (map<char*, room*>::iterator iter = exits.begin(); iter != exits.end(); iter++) {
    if (strcmp(iter->first, input) == 0) {
      return iter->second;
    }
  }
  return NULL;
}

//To list off exits, iterate through all exits and concatenate all exits to empty array
const char* room::listExits() {
  static char listedExits[100];
  const char* space = " ";

  listedExits[0] = '\0'; // Initialize array to empty string

  for (map<char*, room*>::iterator iter = exits.begin(); iter != exits.end(); iter++) {
    strncat(listedExits, iter->first, 99 - strlen(listedExits));
    strncat(listedExits, space, 99 - strnlen(listedExits, sizeof(listedExits)));
  }

  return listedExits;
}
