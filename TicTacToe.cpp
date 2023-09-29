#include <iostream>

using namespace std;

void printBoard();

char board[3][3];
int xmove = 1;
int omove = 1;

void printBoard(char board[3][3]) {//Prints the board
  cout << endl;
  cout << "  0 1 2" << endl;
  cout << "0 ";
  for (int i = 0; i < 3; i++) {//Creates the 1 row
    cout << board[i][0] << " ";
  }
  cout << endl;
  cout << "1 ";
  for (int i = 0; i < 3; i++) {//Creates the 2 row
    cout << board[i][1] << " ";
  }
  cout << endl;
  cout << "2 ";
  for (int i = 0; i < 3; i++) {//Creates the 3 row
    cout << board[i][2] << " ";
  }
  cout << endl; 
} 


int main() {
  int blank = 0;
  int scoreO = 0;
  int scoreX = 0;
  int ties = 0;
  int row = 0;
  int col = 0;
  char xMove = 'X';
  char oMove = 'O';
  bool playing = true;
  int turn = 1;

  while(playing == true) {
    printBoard(board);
    cout << "Enter a row" << endl;
    cin >> row;
    cout << "Enter a column" << endl;
    cin >> col;
    if (0 < row <= 3 || 0 < col <= 3) {
      cout << row << ", " << col << endl;

      if (board[row][col] != xMove || board[row][col] != oMove) {
	  if (turn == xmove) {
	    board[row][col] = xMove;
	    cout << board[row][col] << endl;
	    cout << "xmove" << endl;
	    printBoard(board);
	  }
	  else if (turn == omove) {
	    board[row][col] = oMove;
	    cout << "omove" << endl;
	    printBoard(board);
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
