//Name: Levi L.
//Date: 10/5/23
//Purpose: Play Tic Tac Toe on Cygwin using user-input.
//Credit: Helped by Roger Li on printing out board.


#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
bool checkWin(char board[4][4], char player);
bool checkTie(char board[4][4]); 

int main() {
  //initialize variables
  int scoreO = 0;
  int scoreX = 0;
  int ties = 0;
  int row = 0;
  int col = 0;
  char playagain = ' ';
  char xMove = 'X';
  char oMove = 'O';
  bool playing = true;
  int turn = 0;
  int xturn = 0;
  int oturn = 1;
  char start = true;

  //initialize board
  char board[4][4];

  board[0][0] = ' ';
  board[1][0] = '1';
  board[2][0] = '2';
  board[3][0] = '3';
  board[0][1] = '1';
  board[0][2] = '2';
  board[0][3] = '3';

  //Start game, clear board and print wins
  while(playing == true) { 
    if(start == true) {
      cout << " " << endl;
      cout << "X Wins: " << scoreX << "   O Wins: " << scoreO << "   Ties: " << ties << endl;
      cout << " " << endl;
      
      for(int i = 1; i < 4; i++) {
	for(int j = 1; j < 4; j++) {
	  board[i][j] = ' ';
	}
      }
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
    } start = false;
	    
    
  if(turn == xturn) {
    //X Turn
    //Get input values
    cout << endl;
    cout << "X Turn" << endl;
    cout << "Enter a row" << endl;
    cin >> row;
    cout << "Enter a Col" << endl;
    cin >> col;
    //If move is valid, place on board and array
    if(board[row][col] = ' ' && board[row][col] != oMove && board[row][col] != xMove && row < 4 && col < 4){
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
	//check for tie, ask for play again
	if(checkTie(board) == true) {
          cout << "It's a tie" << endl;
          ties = ties + 1;

          cout << "Play again? Input y or n: " << endl;
          cin >> playagain;
          if(playagain == 'y') {
            playing = true;
            start = true;
	    turn = xturn;
          }
          else if(playagain == 'n'){
            playing = false;
          }
        }

	//check for win, ask for play again
	if(checkWin(board, xMove) == true) {
	  cout << "X Wins" << endl;
	  scoreX = scoreX + 1;
	  
	  cout << "Play again? Input y or n: " << endl;
	  cin >> playagain;
	  if(playagain == 'y') {
	    playing = true;
	    start = true;
	  }
	  else if(playagain == 'n') {
	    playing = false;
	  }
	}
	else{
	  turn = oturn;
	}

    }
    else {
      cout << "Not a valid move" << endl;
      board[row][col] = oMove;
    }
    
  }

  else if(turn == oturn) {
    //O Turn
    //Get input values
    cout << endl;
    cout << "O Turn" << endl;
    cout << "Enter a row" << endl;
    cin >> row;
    cout << "Enter a Col" << endl;
    cin >> col;

    //check if move is valid, place on board and array
    if(board[row][col] = ' ' && board[row][col] != xMove && board[row][col] != oMove && row < 4 && col < 4) {
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

	//check for tie
	if(checkTie(board) == true) {
	  cout << "It's a tie" << endl;
	  ties = ties + 1;

	  cout << "Play again? Input y or n: " << endl;
          cin >> playagain;
          if(playagain == 'y') {
            playing = true;
            start = true;
	    turn = xturn;
          }
          else if(playagain == 'n'){
            playing = false;
          }
	}

	//check for win
	if(checkWin(board, oMove) == true) {
	  cout << "O Wins" << endl;
	  scoreO = scoreO + 1;

	  cout << "Play again? Input y or n: " << endl;
	  cin >> playagain;
	  if(playagain == 'y') {
	    playing = true;
	    start = true;
	  }
	  else if(playagain == 'n'){
	    playing = false;
	  }
	  
	}
	else {
	  turn = xturn;
	}
    }
    else {
      //if invalid, prompt to play different move
      cout << "Not a valid move" << endl;
      board[row][col] = xMove;
    }
    
  }
  
  }
  return 0; 
}


//Check Win Function
bool checkWin(char board[4][4], char player) {
  //Horizontal Wins
  if(board[1][1] == player && board[1][2] == player && board[1][3] == player){
    return true;
  }
  if(board[2][1] == player && board[2][2] == player && board[2][3] == player){
    return true;
  }
  if(board[3][1] == player && board[3][2] == player && board[3][3] == player){
    return true;
  }
  //Vertical Wins
  if(board[1][1] == player && board[2][1] == player && board[3][1] == player){
    return true;
  }
  if(board[1][2] == player && board[2][2] == player && board[3][2] == player){
    return true;
  }
  if(board[1][3] == player && board[2][3] == player && board[3][3] == player){
    return true;
  }
  //Diagonal Wins
  if(board[1][1] == player && board[2][2] == player && board[3][3] == player){
    return true;
  }
  if(board[3][1] == player && board[2][2] == player && board[1][3] == player){
    return true;
  }
  
  return false;
}

//Check Tie Function
bool checkTie(char board[4][4]) {

    for(int i = 1; i < 4; i++) {
      for(int j = 1; j < 4; j++) {
        if(board[i][j] == ' ') {
	  return false;
	}
      }
    } return true;

  }
