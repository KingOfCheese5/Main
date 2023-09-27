#include <iostream>

using namespace std;

void printBoard();

char board[4][4];
int xmove = 1;
int omove = 2;

void printBoard() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      board[i][j] = '-';

    } cout << endl;
  }
    board [0][0] = ' ';
    board [0][1] = '1';
    board [0][2] = '2';
    board [0][3] = '3';

    board [1][0] = '1';
    board [2][0] = '2';
    board [3][0] = '3';

    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
	if(board[i][j] == 'X') {
	  board[i][j] = 'X';
	}
	if(board[i][j] == 'O') {
	  board[i][j] = 'O';
	}
        cout << board[i][j];
      } cout << endl;
    }
}

int main() {
  int blank = 0;
  int scoreO = 0;
  int scoreX = 0;
  int ties = 0;
  int row = 0;
  int col = 0;
  bool playing = true;
  int turn = 1;

  while(playing == true) {
    printBoard();
    cout << "Enter a row" << endl;
    cin >> row;
    cout << "Enter a column" << endl;
    cin >> col;
    if (0 < row <= 3 || 0 < col <= 3) {
      cout << row << ", " << col << endl;

      if (board[row][col] == '-') {
	  if (turn == xmove) {
	    board[row][col] = 'X';
	    cout << board[row][col] << endl;
	    cout << "xmove" << endl;
	    printBoard();
	  }
	  else if (turn == omove) {
	    board[row][col] = omove;
	    cout << "omove" << endl;
	    printBoard();
	  }
	}
    }
      
    else {
      cout << "yuh" << endl;
    }
    playing = false;
    
  }
    
  return 0;
}
