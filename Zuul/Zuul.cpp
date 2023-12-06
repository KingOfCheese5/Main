#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

//void createRooms(vector<room*> &Rooms);

using namespace std;

int main () {
  cout << endl;
  cout << "Welcome to Zuul, you are a student at Galbraith University" << endl;
  cout << "You're hosting a party but need to pick up your friends from around campus" << endl;
  cout << "Once all of your friends are in the car, head to the West Dorms!" << endl;
  char input[81];
  cout << "Your commands are HELP, MOVE, CAR, GET, and DROP" << endl;

  vector<room*> Rooms;

  room* mainStreet = new room();
  room* eastStreet = new room();
  room* westStreet = new room();
  room* westDorms = new room();
  room* eastDorms = new room();
  room* chemLab= new room();
  room* parkingLot = new room();
  room* computerLab = new room();
  room* physicsLab = new room();
  room* chemistryLab = new room();
  room* profOffice = new room();
  room* soccerFields = new room();
  room* basketballCourts = new room();
  room* tennisCourts = new room();
  room* athleticOffice = new room();
  room* pool = new room();
  room* gym = new room();

  //Helped by Vikram Vasudevan and Roger Li
  
  char west[10];
  strcpy(west, "west");
  char north[10];
  strcpy(north, "north");
  char east[10];
  strcpy(east, "east");
  char south[10];
  strcpy(south, "south");

  //Set room descriptions and exits

  strcpy(mainStreet->description, "Main Street");
  mainStreet->roomID = 0;
  mainStreet->setExit(east, eastStreet);
  mainStreet->setExit(west, westStreet);

  strcpy(westStreet->description, "West Street");
  westStreet->roomID = 1;
  westStreet->setExit(east, mainStreet);
  westStreet->setExit(west, computerLab);
  westStreet->setExit(north, westDorms);
  westStreet->setExit(south, chemistryLab);

  strcpy(eastStreet->description, "East Street");
  eastStreet->roomID = 2;
  eastStreet->setExit(east, athleticOffice);
  eastStreet->setExit(west, mainStreet);
  eastStreet->setExit(north, soccerFields);

  strcpy(westDorms->description, "West Dorms");
  westDorms->roomID = 3;
  westDorms->setExit(west, parkingLot);
  westDorms->setExit(south, westStreet);

  strcpy(parkingLot->description, "Parking Lot");
  parkingLot->roomID = 4;
  parkingLot->setExit(east, westDorms);

  strcpy(computerLab->description, "Computer Lab");
  computerLab->roomID = 5;
  computerLab->setExit(east, westStreet);
  computerLab->setExit(south, physicsLab);

  strcpy(physicsLab->description, "Physics Lab");
  physicsLab->roomID = 6;
  physicsLab->setExit(north, computerLab);
  physicsLab->setExit(east, chemistryLab);
  physicsLab->setExit(south, profOffice);

  strcpy(chemistryLab->description, "Chemistry Lab");
  chemistryLab->roomID = 7;
  chemistryLab->setExit(west, physicsLab);
  chemistryLab->setExit(north, westStreet);

  strcpy(profOffice->description, "Professor's Office");
  profOffice->roomID = 8;
  profOffice->setExit(north, physicsLab);

  strcpy(soccerFields->description, "Soccer Fields");
  soccerFields->roomID = 9;
  soccerFields->setExit(east, basketballCourts);
  soccerFields->setExit(south, eastStreet);

  strcpy(basketballCourts->description, "Basketball Courts");
  basketballCourts->roomID = 10;
  basketballCourts->setExit(east, tennisCourts);
  basketballCourts->setExit(west, soccerFields);
  basketballCourts->setExit(north, eastDorms);
  basketballCourts->setExit(south, athleticOffice);

  strcpy(eastDorms->description, "East Dorms");
  eastDorms->roomID = 11;
  eastDorms->setExit(south, basketballCourts);

  strcpy(tennisCourts->description, "Tennis Courts");
  tennisCourts->roomID = 12;
  tennisCourts->setExit(west, basketballCourts);

  strcpy(athleticOffice->description, "Athletic Office");
  athleticOffice->roomID = 13;
  athleticOffice->setExit(north, basketballCourts);
  athleticOffice->setExit(west, eastStreet);
  athleticOffice->setExit(south, pool);

  strcpy(pool->description, "Swimming Pool");
  pool->roomID = 14;
  pool->setExit(north, athleticOffice);
  pool->setExit(west, gym);

  strcpy(gym->description, "Gym");
  gym->roomID = 15;
  gym->setExit(east, pool);
  
  Rooms.push_back(mainStreet);
  Rooms.push_back(eastStreet);
  Rooms.push_back(westStreet);
  Rooms.push_back(eastDorms);
  Rooms.push_back(westDorms);
  Rooms.push_back(chemLab);
  Rooms.push_back(parkingLot);
  Rooms.push_back(computerLab);
  Rooms.push_back(physicsLab);
  Rooms.push_back(chemistryLab);
  Rooms.push_back(profOffice);
  Rooms.push_back(soccerFields);
  Rooms.push_back(basketballCourts);
  Rooms.push_back(tennisCourts);
  Rooms.push_back(athleticOffice);
  Rooms.push_back(pool);
  Rooms.push_back(gym);
  
  //vector<Person*> car;
  
  bool running = true;
  while(running == true) {
    cout << endl;
    cout << "What would you like to do?" << endl;
    cin.getline(input, 81, '\n');

    return 0;
  }
}
