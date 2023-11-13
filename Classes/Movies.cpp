#include <iostream>
#include "Movies.h"

using namespace std;

//input movie info
Movies:: Movies() : Media() {
  cout << "Enter Director" << endl;
  cin.getline(director, 81, '\n');
  cout << "What is the duration of the movie(minutes)?" << endl;
  cin >> duration;
  cin.clear();
  cin.ignore(1000, '\n');
  cout << "Enter a non-zero rating" << endl;
  cin >> rating;
  cin.ignore(1000, '\n');
}

//getter function
void Movies::getInformation() {
  cout << "Title: " << title << ", Year: " << year << ", Director: " << director << ", Duration: " << duration << ", Rating: " << rating << endl;
  return;
}
