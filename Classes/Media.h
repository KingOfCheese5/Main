#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  Media(char*);
  char* getDescription();
  int getID();
 private:
  char* description;
  int id;

};
