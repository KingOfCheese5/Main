#include <iostream>
#include "Music.h"

using namespace std;

//input music info
Music::Music() : Media(){
  cout << "Enter Artist" << endl;
  cin.getline(artist, 81, '\n');
  cout << "What is the duration of the song(seconds)?" << endl;
  cin.clear();
  cin >> duration;
  cin.ignore(1000, '\n');
  while(rating == 0) {
    cout << "Enter a non-zero rating" << endl;
    cin.clear();
    cin >> rating;
    cin.ignore(1000, '\n');
  }
}

//Return music info
void Music::getInformation() {
  cout << "Track: " << title << ", Year: " << year << ", Artist: " << artist << ", Rating: " << endl;
  return;
}
