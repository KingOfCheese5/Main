#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


int main() {
  int scoreO = 0;
  int scoreX = 0;
  int ties = 0;
  int row = 0;
  int col = 0;
  char xMove = 'X';
  char oMove = 'O';
  bool playing = true;
  int turn = 0;
  int xturn = 0;
  int oturn = 1;
  char start = true;

  char board[4][4];

  board[0][0] = ' ';
  board[1][0] = '1';
  board[2][0] = '2';
  board[3][0] = '3';
  board[0][1] = '1';
  board[0][2] = '2';
  board[0][3] = '3';

  while(playing == true) { 
    if(start == true) {
      for(int i = 1; i < 4; i++) {
	for(int j = 1; j < 4; j++) {
	  board[i][j] = ' ';
	}
      }
    } start = false;
      

  
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(j < 3) {
	cout << board[i][j];
      }
      if(j == 3) {
	cout << board[i][j] << endl;
      }
    }
  }

  
  if(turn == xturn) {
    //X Turn
    //Get input values
    cout << endl;
    cout << "Enter a row" << endl;
    cin >> row;
    cout << "Enter a Col" << endl;
    cin >> col;
    
    if(board[row][col] = ' ') {
      board[row][col] = xMove;
      
      for(int i = 0; i < 4; i++) {
	for(int j = 0; j < 4; j++) {
	  if(j < 3) {
	    cout << board[i][j];
	  }
	  if(j == 3) {
	    cout << board[i][j] << endl;
	  }
	}
      }
    }
    turn = oturn;
  }

  if(turn == oturn) {
    //O Turn
    //Get input values
    cout << endl;
    cout << "Enter a row" << endl;
    cin >> row;
    cout << "Enter a Col" << endl;
    cin >> col;
    
    if(board[row][col] = ' ') {
      board[row][col] = oMove;

      for(int i = 0; i < 4; i++) {
	for(int j = 0; j < 4; j++) {
	  if(j < 3) {
	    cout << board[i][j];
	  }
	  if(j == 3) {
	    cout << board[i][j] << endl;
	  }
	}
      }
    }
    
    turn = xturn;
  }
    
  }
  return 0; 
}

