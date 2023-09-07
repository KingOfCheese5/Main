#include <iostream>

using namespace std;

//drivers code
int main() {
  int random = 0;
  srand(time(NULL));
  random = rand() % 100 + 1;
  int guesses = 0;
  int input;

  bool playing = true;

  while(playing == true) {

    if(input > random){
      cout << input << endl;
      
    }
    
  }
  
  if(input > 0){
    cout << random << endl;
  }

  //cin -> takes in input
  //cout -> prints output
  

  return 0;
}
