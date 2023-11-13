#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;
//Initialize Functions
void ADD(vector<Media*>* media);
void SEARCH(vector<Media*>* media);
void DELETE(vector<Media*>* media);

int main() {
  //Intialize Variables
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
    if(strcmp(input, add1) == 0) {
      //Add entry
      ADD(media);
    }
    if(strcmp(input, search1) == 0) {
      //Search for entry
      SEARCH(media);
    }
    if(strcmp(input, delete1) == 0) {
      //Delete entry
      DELETE(media);
    }
    if(strcmp(input, quit1) == 0) {
      //Exit program
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

    //Add game to media
    if(strcmp(input, games) == 0) {
      VideoGames* videogames = new VideoGames();
      media->push_back(videogames);
      running = false;
    }
    //Add song to media
    if(strcmp(input, music) == 0) {
      Music* music = new Music();
      media->push_back(music);
      running = false;
    }
    //Add movie to media
    if(strcmp(input, movies) == 0) {
      Movies* movies = new Movies();
      media->push_back(movies);
      running = false;
    }

    running = false;
  }
}

void SEARCH(vector<Media*>* media) {
  char input[81];
  bool running = true;
  char title[81] = "title";
  char year[81] = "year";
  char quit[81] = "quit";

  while(running == true) {

    cout << endl;
    cout << "Would you like to search by 'title' or by 'year'?" << endl;
    cout << "If you would like to exit, enter 'quit'" << endl;
    cin.getline(input, 81, '\n');

    for(int i = 0; i < strlen(input); i++){
      //Helped by Ethan Kusse, checks for non-alphabet and removes them
      if(!isalpha(input[i])){
        memmove(input+i, input+1+i, strlen(input)-i);
        i--;
      }
    }
    //Iterate through all entries in media, print information given title
    if(strcmp(input, title) == 0) {
      cout << "Enter the title: " << endl;
      cin.getline(input, 81, '\n');
      vector<Media*>::iterator iter = media->begin();
      for(iter; iter < media->end(); iter++) {
	if(strcmp(input, (*iter)->getTitle()) == 0) {
	  (*iter)->getInformation();
	  return;
	}
      }
    }
    //Iterate through all entries in media, print information given year
    if(strcmp(input, year) == 0) {
      cout << "Enter the year: " << endl;
      cin >> input;
      vector<Media*>::iterator iter = media->begin();
      if(atoi(input) == (*iter)->getYear()) {
	(*iter)->getInformation();
	return;
      }
    }
    //Quit program
    if(strcmp(input, quit) == 0) {
      cout << "Exited to Main Menu" << endl;
      return;
    }
  }
}

void DELETE(vector<Media*>* media) {
  char input[81];
  bool running = true;
  char title[81] = "title";
  char year[81] = "year";
  char quit[81] = "quit";
  char yes[81] = "Yes";
  char no[81] = "No";

  while(running == true) {

    cout << endl;
    cout << "Would you like to search for the entry by 'title' or by 'year'?" << endl;
    cout << "If you would like to exit, enter 'quit'" << endl;
    cin.getline(input, 81, '\n');

    for(int i = 0; i < strlen(input); i++){
      //Helped by Ethan Kusse, checks for non-alphabet and removes them
      if(!isalpha(input[i])){
        memmove(input+i, input+1+i, strlen(input)-i);
        i--;
      }
    }
    if(strcmp(input, title) == 0) {
      cout << "Enter the title: " << endl;
      cin.getline(input, 81, '\n');
      vector<Media*>::iterator iter = media->begin();
      for(iter; iter < media->end(); iter++) {
        if(strcmp(input, (*iter)->getTitle()) == 0) {
          (*iter)->getInformation();
          cout << "Would you like to delete this entry, enter 'Yes' or 'No'? ";
	  cin.getline(input, 81, '\n');
	  //Delete value from iterator and remove from vector
	  if(strcmp(input, yes) == 0) {
	    delete *iter;
	    media->erase(iter);
	    return;
	  }
	  if(strcmp(input, no) == 0) {
	    return;
	  }
        }
      }
    }
    if(strcmp(input, year) == 0) {
      cout << "Enter the year: " << endl;
      cin >> input;
      vector<Media*>::iterator iter = media->begin();
      if(atoi(input) == (*iter)->getYear()) {
        (*iter)->getInformation();
	cout << "Would you like to delete this entry, enter 'Yes' or 'No'? ";
	cin.getline(input, 81, '\n');
	//Delete value from iterator and remove from vector
        if(strcmp(input, yes) == 0) {
	  delete *iter;
          media->erase(iter);
          return;
	}
	if(strcmp(input, no) == 0) {
	  return;
	}
      }
    }
    //exit program
    if(strcmp(input, quit) == 0) {
      cout << "Exited to Main Menu" << endl;
      return;
    }
  }


}
