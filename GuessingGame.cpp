//Levi Lao
//Last Edited: 8/7/23
//Project: Guessing Game: User guesses are received and then resent as user
// attempts to guess a randomized number.

#include <iostream>

using namespace std;

int main()
{
  //initialize variables
  bool playing = true;
  int random = 0;
  int input = 0;
  int tries = 0;
  int generate = 0;
  char playagain;

  //Create random number
  srand(time(NULL));
  random = rand();
  random = random % 100;
  
  
  //Check each input for correct number
  while(playing == true) {
    cout << "Enter a guess" << endl;
    cin >> input;

    //number is too high
    if (input > random) {
      cout << "Your number is too high" << endl;
      tries++;
    }
    //number is too low
    if (input < random) {
      cout << "Your number is too low" << endl;
      tries++;
    }
    //number is correct
    if (input == random) {
      cout << "Correct!" << endl;
      tries++;
      cout << "Tries: " << tries << endl;
      playing = false;

      cout << "Play again? Input y or n:" << endl;
      cin >> playagain;
    }
    //If playing again, create new number and reset tries
    if(playagain == 'y') {
      playing = true;
      tries = 0;
      srand(time(NULL));
      random = rand() % 100 + 1;
      cout << random << endl;
    }
    if(playagain == 'n') {
      playing = false;
    }


  }
  //return 0
  return 0;
}
