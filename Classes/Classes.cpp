#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "VideoGames.h"

using namespace std;
void ADD(vector<Media*>* media);

int main() {
  bool running = true;
  char input[81];
  char add1[] = "ADD";
  char search1[] = "SEARCH";
  char delete1[] = "DELETE";
  char quit1[] = "QUIT";
 
  vector<Media*>* media = new vector<Media*>();

  while(running == true) {
    
    cout << endl;
    cout << "Enter ADD, SEARCH, DELETE to access files." << endl;
    cout << "Else, enter QUIT to exit program" << endl;
    cin.getline(input, 81, '\n');

    for(int i = 0; i < strlen(input); i++){
      //Helped by Ethan Kusse, checks for non-alphabet and removes them
      if(!isalpha(input[i])){
        memmove(input+i, input+1+i, strlen(input)-i);
        i--;
      }
    }
    if(strcmp(input, "ADD") == 0) {
      ADD(media);
    }
    if(strcmp(input, search1) == 0) {
      cout << "strcmp working search" << endl;
    }
    if(strcmp(input, delete1) == 0) {
      cout << "strcmp working delete" << endl;
    }
    if(strcmp(input, quit1) == 0) {
      cout << "Program Exited" << endl;
      return 0;
    }

  }

}


void ADD(vector<Media*>* media) {
  bool running = true;
  char input[81];
  char movies[] = "MOVIES";
  char music[] = "MUSIC";
  char games[] = "VIDEOGAMES";
  
  
  while(running == true) {
    cout << "What type of media would you like to add: VIDEOGAMES, MUSIC, or MOVIES?" << endl;
    cin.getline(input, 81, '\n');

    if(strcmp(input, games) == 0) {
      cout << "Games" << endl;
      VideoGames* videogames = new VideoGames();
      media->push_back(videogames);
      running = false;
    }
    if(strcmp(input, music) == 0) {
      cout << "Music" << endl;
    }
    if(strcmp(input, movies) == 0) {
      cout << "Movies" << endl;
    }

    running = false;
  }
}
