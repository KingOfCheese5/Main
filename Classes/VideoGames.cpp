#include <iostream>
#include "VideoGames.h"

using namespace std;

//input video games info
VideoGames::VideoGames() : Media(){
  cout << "Enter publisher: " << endl;
  cin.clear();
  cin >> publisher;
  cin.ignore(1000, '\n');
  while(rating == 0){
    cout << "Enter a non-zero rating" << endl;
    cin.clear();
    cin >> rating;
    cin.ignore(1000, '\n');
  }
}
//return information about video game object
void VideoGames::getInformation(){
  cout << "Title: " << title << ", Year: " << year << ", Publisher: " << publisher << ", Rating: " << rating << endl;
  return;
}
