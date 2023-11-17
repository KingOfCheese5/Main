#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

int main () {
  cout << endl;
  cout << "Welcome to Zuul, you are a student at Galbraith University" << endl;
  cout << "You agreed to play tennis with your friends at the nearby courts" << endl;
  cout << "You can't seem to find your racket, maybe it's in the car..." << endl;
  char input[81];
  cout << "Your commands are HELP, MOVE, INVENTORY, GET, and DROP" << endl;

  vector<Room*>* rooms = new vector<Room*>();
  vector<Item*>* inventory = new vector<Item*>();
  
  bool running = true;
  while(running == true) {
    cout << endl;
    cout << "What would you like to do?" << endl;
    cin.getline(input, 81, '\n');


    Room* mainStreet = new room();
    Room* eastStreet = new room();
    Room* westStreet = new room();
    Room* westDorms = new room();
    Room* eastDorms = new room();
    Room* chemLab= new room();
    Room* parkingLot = new room();
    Room* computerLab = new room();
    Room* physicsLab = new room();
    Room* chemistryLab = new room();
    Room* profOffice = new room();
    Room* soccerFields = new room();
    Room* basketballCourts = new room();
    Room* tennisCourts = new room();
    Room* athleticOffice = new room();
    Room* pool = new room();
    Room* gym = new room();




  return 0;
}
