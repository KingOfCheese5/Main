#ifndef VIDEOGAMES
#define VIDEOGAMES
#include <iostream>
#include "Media.h"

//videogames struct

class VideoGames : public Media{
public:
  VideoGames();
  int rating = 0;
  char publisher[80];
  void getInformation();
};

#endif
