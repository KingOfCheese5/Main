#ifndef MOVIE
#define MOVIE
#include <iostream>
#include "Media.h"

//Movie struct
class Movies : public Media {
 public:
  Movies();
  int rating = 0;
  int duration = 0;
  char director[80];
  void getInformation();
};

#endif
