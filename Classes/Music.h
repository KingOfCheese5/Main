#ifndef MUSIC
#define MUSIC
#include <iostream>
#include "Media.h"

//Music struct
class Music : public Media {
 public:
  Music();
  int rating = 0;
  int duration = 0; 
  char artist[80];
  void getInformation();
};
  
  
#endif
