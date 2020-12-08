#include "Piezas.h"
#include <vector>
/** CLASS Piezas
* Class for representing a Piezas vertical board, which is roughly based
* on the game "Connect Four" where pieces are placed in a column and
* fall to the bottom of the column, or on top of other pieces already in
* that column. For an illustration of the board, see:
*  https://en.wikipedia.org/wiki/Connect_Four
*
* Board coordinates [row,col] should match with:
* [2,0][2,1][2,2][2,3]
* [1,0][1,1][1,2][1,3]
* [0,0][0,1][0,2][0,3]
* So that a piece dropped in column 2 should take [0,2] and the next one
* dropped in column 2 should take [1,2].
**/


/**
* Constructor sets an empty board (default 3 rows, 4 columns) and
* specifies it is X's turn first
**/
Piezas::Piezas() {
  board.resize(BOARD_ROWS);
  for(int i = 0; i < BOARD_ROWS; i++) {
    board[i].resize(BOARD_COLS);
  }
  reset();
  turn = X;
} // Piezas()

/**
* Resets each board location to the Blank Piece value, with a board of the
* same size as previously specified
**/
void Piezas::reset() {
  for(int i = 0; i < BOARD_ROWS; i++) {
    for(int j = 0; j < BOARD_COLS; j++) {
      board[i][j] = Blank;
    }
  }
} // reset()

/**
* Places a piece of the current turn on the board, returns what
* piece is placed, and toggles which Piece's turn it is. dropPiece does
* NOT allow to place a piece in a location where a column is full.
* In that case, placePiece returns Piece Blank value
* Out of bounds coordinates return the Piece Invalid value
* Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column) {
  // First toggle turns bc it doesn't matter if the move is valid or not
  Piece realTurn = turn;
  if(turn == X) {
    turn = O;
  }
  else {
    turn = X;
  }

  // Then we will check if the move is valid
  if(column >= BOARD_COLS || column < 0) {
    return Invalid;
  }

  // Then check the board starting at the bottom row for an empty square
  bool dropped = false;
  for(int i = BOARD_ROWS - 1; i > -1; i--) {
    if(board[i][column] == Blank){
      dropped = true;
      board[i][column] = realTurn;
      break;
    }
  }

  if(!dropped) {
    return Blank;
  }
  return realTurn;
} // dropPiece()

/**
* Returns what piece is at the provided coordinates, or Blank if there
* are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
  // Check if the coordinates are out of bounds
  if(row >= BOARD_ROWS || row < 0) {
    return Invalid;
  }
  if(column >= BOARD_COLS || column < 0) {
    return Invalid;
  }

  // Just return what's at the board since it
  //   will be Blank if no one has moved there
  return board[row][column];
} // pieceAt()

/**
* Returns which Piece has won, if there is a winner, Invalid if the game
* is not over, or Blank if the board is filled and no one has won ("tie").
* For a game to be over, all locations on the board must be filled with X's
* and O's (i.e. no remaining Blank spaces). The winner is which player has
* the most adjacent pieces in a single line. Lines can go either vertically
* or horizontally. If both X's and O's have the same max number of pieces in a
* line, it is a tie.
**/
Piece Piezas::gameState() {
  // Check if any the squares are empty
  for(int i = 0; i < BOARD_ROWS; i++) {
    for(int j = 0; j < BOARD_COLS; j++) {
      if(board[i][j] == Blank) {
        return Invalid;
      }
    }
  }

  int longest_X = 0;
  int longest_O = 0;

  // Rows forwards
  for(int i = 0; i < BOARD_ROWS; i++) {
    int current = 0;
    Piece temp = board[i][0];
    for(int j = 0; j < BOARD_COLS; j++) {
      if(temp == board[i][j]) {
        current++;
      }
      else {
        break; // we break bc it breaks the chain
      }
    }
    if(temp == O && current > longest_O) {
      longest_O = current;
    }
    if(temp == X && current > longest_X) {
      longest_X = current;
    }
  }

  // Rows backwards
  for(int i = 0; i < BOARD_ROWS; i++) {
    int current = 0;
    Piece temp = board[i][BOARD_COLS - 1];
    for(int j = BOARD_COLS - 1; j < -1; j--) {
      if(temp == board[i][j]) {
        current++;
      }
      else {
        break; // we break bc it breaks the chain
      }
    }
    if(temp == O && current > longest_O) {
      longest_O = current;
    }
    if(temp == X && current > longest_X) {
      longest_X = current;
    }
  }

  // Cols forwards
  for(int i = 0; i < BOARD_COLS; i++) {
    int current = 0;
    Piece temp = board[0][i];
    for(int j = 0; j < BOARD_ROWS; j++) {
      if(temp == board[j][i]) {
        current++;
      }
      else {
        break; // we break bc it breaks the chain
      }
    }
    if(temp == O && current > longest_O) {
      longest_O = current;
    }
    if(temp == X && current > longest_X) {
      longest_X = current;
    }
  }

  // Cols backwards
  for(int i = 0; i < BOARD_COLS; i++) {
    int current = 0;
    Piece temp = board[BOARD_ROWS - 1][0];
    for(int j = BOARD_ROWS - 1; j < -1; j--) {
      if(temp == board[j][i]) {
        current++;
      }
      else {
        break; // we break bc it breaks the chain
      }
    }
    if(temp == O && current > longest_O) {
      longest_O = current;
    }
    if(temp == X && current > longest_X) {
      longest_X = current;
    }
  }

  if(longest_X > longest_O) {
    return X;
  }
  else if(longest_X < longest_O) {
    return O;
  }
  return Blank;
} // gameState()
