//Levi Lao
//1/22/24
//Zuul Game: Navigate around a map and collect items using room pointer functionality. 

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

  strcpy(mainStreet->description, "Main Street, it's bustling with busy students ");
  mainStreet->roomID = 0;
  mainStreet->setExit(east, eastStreet);
  mainStreet->setExit(west, westStreet);

  strcpy(westStreet->description, "West Street, you walk here to get to many of your classes");
  westStreet->roomID = 1;
  westStreet->setExit(east, mainStreet);
  westStreet->setExit(west, computerLab);
  westStreet->setExit(north, westDorms);
  westStreet->setExit(south, chemistryLab);

  strcpy(eastStreet->description, "East Street, you walk here to get to the athletic facilities");
  eastStreet->roomID = 2;
  eastStreet->setExit(east, athleticOffice);
  eastStreet->setExit(west, mainStreet);
  eastStreet->setExit(north, soccerFields);

  strcpy(westDorms->description, "West Dorms, you live here. A massive party seems to be taking place");
  westDorms->roomID = 3;
  westDorms->setExit(west, parkingLot);
  westDorms->setExit(south, westStreet);

  strcpy(parkingLot->description, "Parking Lot, the lot is fairly full, most students are out");
  parkingLot->roomID = 4;
  parkingLot->setExit(east, westDorms);

  strcpy(computerLab->description, "Computer Lab, you peer in and see students coding... something");
  computerLab->roomID = 5;
  computerLab->setExit(east, westStreet);
  computerLab->setExit(south, physicsLab);

  strcpy(physicsLab->description, "Physics Lab, an intense notetaking session seems to be taking place");
  physicsLab->roomID = 6;
  physicsLab->setExit(north, computerLab);
  physicsLab->setExit(east, chemistryLab);
  physicsLab->setExit(south, profOffice);

  strcpy(chemistryLab->description, "Chemistry Lab, you see students in labcoats peer at their lab benches");
  chemistryLab->roomID = 7;
  chemistryLab->setExit(west, physicsLab);
  chemistryLab->setExit(north, westStreet);

  strcpy(profOffice->description, "Professor's Office, your favorite professor seems to be out...");
  profOffice->roomID = 8;
  profOffice->setExit(north, physicsLab);

  strcpy(soccerFields->description, "Soccer Fields, you can spot some rec teams sparring off in the distance");
  soccerFields->roomID = 9;
  soccerFields->setExit(east, basketballCourts);
  soccerFields->setExit(south, eastStreet);

  strcpy(basketballCourts->description, "Basketball Courts, you may come back to shoot some hoops later");
  basketballCourts->roomID = 10;
  basketballCourts->setExit(east, tennisCourts);
  basketballCourts->setExit(west, soccerFields);
  basketballCourts->setExit(north, eastDorms);
  basketballCourts->setExit(south, athleticOffice);

  strcpy(eastDorms->description, "East Dorms, your friend Terquavion lives here. ");
  eastDorms->roomID = 11;
  eastDorms->setExit(south, basketballCourts);

  strcpy(tennisCourts->description, "Tennis Courts, you don't have your racket, but you might be back tomorrow");
  tennisCourts->roomID = 12;
  tennisCourts->setExit(west, basketballCourts);

  strcpy(athleticOffice->description, "Athletic Office, trophies from ages past line the old shelves of the office");
  athleticOffice->roomID = 13;
  athleticOffice->setExit(north, basketballCourts);
  athleticOffice->setExit(west, eastStreet);
  athleticOffice->setExit(south, pool);

  strcpy(pool->description, "Swimming Pool, there seems to be another party going on near the water...");
  pool->roomID = 14;
  pool->setExit(north, athleticOffice);
  pool->setExit(west, gym);

  strcpy(gym->description, "Gym, your favorite spot on campus. You set the record for the bench-press years prior");
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


  //Idea from Roger Li
  //Instead of making vector of "items", set items to booleans
  //Edit properties of room pointers so items can be attached
  
  eastDorms->getTerquavion = true;
  bool playerGetTerquavion = false;
  parkingLot->getTessa = true;
  bool playerGetTessa = false;
  profOffice->getEli = true;
  bool playerGetEli = false;
  gym->getVictor = true;
  bool playerGetVictor = false;
  tennisCourts->getSaahil = true;
  bool playerGetSaahil = false;

  
  //current room points to a room in the vector, starting in mainStreet
  room* currentRoom = mainStreet;
   cout << currentRoom->getDescription() << endl;
   cout << "Exits: " << endl;
   cout << currentRoom->listExits() << endl;

  
  bool running = true;
  while(running == true) {
    cout << endl;
    cout << "What would you like to do?" << endl;
    cin.getline(input, 81, '\n');

    if(strcmp(input, "HELP") == 0) {
      
      cout << "Enter MOVE, GO, CAR, or GET to progress the game" << endl;
      cout << "Pick up your friends and head to the party" << endl;

    }
    
    if(strcmp(input, "MOVE") == 0) {

      bool stillRunning = true;
      while(stillRunning == true) {

	cout << "What direction?";
	char direction[10];
	cin.get(direction, 10);
	cin.get();

	//if room exit does not exist
	if(currentRoom->getExit(direction) == NULL) {
	  cout << "No exit there" << endl;
	}
	
	else {

	  //set room
	  currentRoom = currentRoom->getExit(direction);

	  //if player wins game
	  if ((currentRoom == westDorms) && (playerGetTerquavion == true)
		   && (playerGetTessa == true) && (playerGetEli == true)
		   && (playerGetVictor == true) && (playerGetSaahil == true)) {
	    cout << "Hey you're late to the party. Come on in!" << endl;
	    running = false;
	    stillRunning = false;
	    return 0;
	   }

	  else {
	    //print room and description
	    cout << endl;
	    cout << currentRoom->getDescription() << endl;
	    cout << "Exits: " << endl;
	    cout << currentRoom->listExits() << endl;
	    stillRunning = false;
	  }
	}

      }
    }

    //Show "inventory", print if statement is true
    if(strcmp(input, "CAR") == 0) {
      
       cout << "In your car, there's... ";
       int people = 0;
	
       if(playerGetTerquavion == true) {
	 cout << "Terquavion ";
	 people++;
       }

       if(playerGetTessa == true) {
	 cout << "Tessa ";
	 people++;
       }

       if(playerGetEli == true) {
	 cout << "Eli ";
	 people++;
       }

       if(playerGetVictor == true) {
         cout << "Victor ";
         people++;
       }

       if(playerGetSaahil == true) {
	 cout << "Saahil ";
	 people++;
       }
       
       if(people = 0) {
	 cout << "nobody in the car";
       }
       
       cout << endl;

    }

    //get person(item), check if the room has person, then set inventory get to true
    if(strcmp(input, "GET") == 0) {
	 if ((currentRoom->getTerquavion == true) || (currentRoom->getTessa == true)
	         || (currentRoom->getEli == true) || (currentRoom->getVictor == true)
	         || (currentRoom->getSaahil == true))
	   {
	     cout << "Pick up who?" << endl;
	     char pickupPeople[40];
	     cin.get(pickupPeople, 40);
	     cin.get();
	     if ((currentRoom->getTerquavion == true) && (strcmp(pickupPeople, "Terquavion") == 0)) {
	       cout << "Terquavion: 'I was so bored, let's go!' " << endl;
	       playerGetTerquavion = true;
	       currentRoom->getTerquavion = false;
	     }
	     else if((currentRoom->getTessa == true) && (strcmp(pickupPeople, "Tessa") == 0)) {
               cout << "Tessa: 'Ready to party?' " << endl;
               playerGetTessa = true;
               currentRoom->getTessa = false;
	     }
	     else if((currentRoom->getEli == true) && (strcmp(pickupPeople, "Eli") == 0)) {
               cout << "Eli: 'Was actually looking for my professor, I'll hitch a ride though' " << endl;
               playerGetEli = true;
               currentRoom->getEli = false;
             }
	     else if((currentRoom->getVictor == true) && (strcmp(pickupPeople, "Victor") == 0)) {
               cout << "Victor: 'Been waiting all day for this...' " << endl;
               playerGetVictor = true;
               currentRoom->getVictor = false;
             }
	     else if((currentRoom->getSaahil == true) && (strcmp(pickupPeople, "Saahil") == 0)) {
               cout << "Saahil: 'Ooh I'm still a little sweaty, we can go though' " << endl;
               playerGetSaahil = true;
               currentRoom->getSaahil = false;
             }
	     //no people in room
	     else {
	       cout << "There's nobody there..." << endl;
	     }
	   }
      }
    //drop off people, check if they have person, then drop into room and set roomget to true
    if(strcmp(input, "DROP") == 0) {
      if(playerGetTerquavion == true || playerGetTessa == true  ||
	 playerGetEli == true        || playerGetVictor == true ||
	 playerGetSaahil == true)
	{
	  cout << "Who would you like to drop off?" << endl;
	  char dropOffPeople[40];
          cin.get(dropOffPeople, 40);
          cin.get();
	  
	  //set room hasItem statement to true and set player hasItem to false
	  if ((playerGetTerquavion == true) && (strcmp(input, "Terquavion") == 0)) {
	    cout << "Terquavion: 'I don't know if this is the spot...' ";
	    playerGetTerquavion = false;
	    currentRoom->getTerquavion = true;
	  }
	  else if ((playerGetTessa == true) && (strcmp(input, "Tessa") == 0)){
	    cout << "Tessa: 'You sure you got the right directions?' ";
	    playerGetTessa = false;
	    currentRoom->getTessa = true;
	  }
	   else if ((playerGetEli == true) && (strcmp(input, "Eli") == 0)){
            cout << "Eli: 'Doesn't look like a party to me...' ";
            playerGetEli = false;
            currentRoom->getEli = true;
          }
	   else if ((playerGetVictor == true) && (strcmp(input, "Victor") == 0)){
            cout << "Victor: 'You sure you got the right directions?' ";
            playerGetVictor = false;
            currentRoom->getVictor = true;
          }
	   else if ((playerGetSaahil == true) && (strcmp(input, "Saahil") == 0)){
            cout << "Saahil: 'You sure you got the right directions?' ";
            playerGetSaahil = false;
            currentRoom->getSaahil = true;
          }
	}
      else {
	cout << "There's nobody in the car!" << endl;
      }
    }
  }
}
