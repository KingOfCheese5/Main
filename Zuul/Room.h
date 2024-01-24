//Header Guard
#ifndef ROOM
#define ROOM

#include <iostream>
#include <map>

using namespace std;
//Room class data
class room{
 public:
  room();
  char description[200];
  int roomID;
  map<char*, room*> exits;


  //set exits
  
  int exitN;
  int exitS;
  int exitE;
  int exitW;

  int hasExitN;
  int hasExitS;
  int hasExitE;
  int hasExitW;

  //getters and setters
  
  char* getDescription();

  void setRoomID(int x);
  void setExit(char* dir, room* r);
  room* getExit(char* input);
  const char* listExits();
  
  bool getTerquavion;
  bool getTessa;
  bool getEli;
  bool getVictor;
  bool getSaahil;
  

};

#endif
