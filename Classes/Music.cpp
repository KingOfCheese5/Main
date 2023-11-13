#include <iostream>
#include "Music.h"

using namespace std;

//input music info
Music::Music() : Media(){
  cout << "Enter the name of the artist" << endl;
  cin >> artist;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "What is the duration of the song(seconds)?" << endl;
  cin >> duration;
  cin.clear();
  cin.ignore(10000, '\n');
  cout << "Enter the publisher of the song" << endl;
  cin >> publisher;
  cin.clear();
  cin.ignore(10000, '\n');
}


//Return music info
void Music::getInformation() {
  cout << "Track: " << title << ", Year: " << year << ", Artist: " << artist << ", Publisher: " << publisher << ", Duration: " << duration << endl;
  return;
}
