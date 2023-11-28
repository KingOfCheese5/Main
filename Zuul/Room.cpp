#include <iostream>
#include <cstring>
#include "room.h"
#include <map>

using namespace std;

room::room() {

}

char*room::getDescription() {

}

void room::setRoomID(int x) {
  roomID = x;
}

void room::setExit(char* dir, room* room) {
  exits.insert(pair<char*>, 
