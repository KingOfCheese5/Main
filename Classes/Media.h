//Header Guard
#ifndef MEDIA
#define MEDIA

#include <iostream>

using namespace std;

//media class struc
class Media{
  
 public:
  Media();
  char* getTitle();
  virtual void getInformation();
  int getYear();
  
 protected:
  int id;
  int year;
  char title[80];
};

#endif
