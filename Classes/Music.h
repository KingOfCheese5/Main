#ifndef MUSIC
#define MUSIC
#include <iostream>
#include "Media.h"

//Music struct
class Music : public Media {
 public:
  Music();
  char publisher[80];
  int duration = 0; 
  char artist[80];
  void getInformation();
};
  
  
#endif
