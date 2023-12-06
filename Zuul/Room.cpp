#include <iostream>
#include <cstring>
#include "Room.h"
#include <map>

using namespace std;

room::room() {

}

char*room::getDescription() {
  return description;
}

void room::setRoomID(int x) {
  roomID = x;
}

void room::setExit(char* dir, room* r) {
  exits.insert(pair<char*, room*>(dir, r));
}

room* room::getExit(char* input) {
  map<char*, room*>::iterator iter = exits.begin();
  while (iter != exits.end()) {
    if(strcmp(iter->first, input) == 0) {
      return iter->second;	
    }
  }
  return NULL;

}
