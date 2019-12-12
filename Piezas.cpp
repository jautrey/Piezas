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
Piezas::Piezas()
{
  board.resize(BOARD_ROWS, std::vector<Piece>(BOARD_COLS, Blank));
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  std::vector < std::vector<Piece> > newBoard;
  newBoard.resize(BOARD_ROWS, std::vector<Piece>(BOARD_COLS, Blank));
  board = newBoard;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  Piece cur;
  if(turn == X)
  {
    cur = X;
    turn = O;
  }
  else
  {
    cur = O;
    turn = X;
  }

  //out of bounds
  if(column >= 4 || column < 0)
  {
    return Invalid;
  }

  for(int i = 0; i < 3; i++)
  {
    if(board[i][column] == Blank)
    {
      board[i][column] = cur;
      return cur;
    }
  }

    return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(column >= 4 || column < 0 || row >= 3 || row < 0)
  {
    return Invalid;
  }

  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{

  //game not over
  for(int i = 0; i < BOARD_COLS; i++)
  {
    for(int j = 0; j < BOARD_ROWS; j++)
    {
      if(board[j][i] == Blank)
      {
        return Invalid;
      }
    }
  }

  Piece lastPiece = Invalid;
  int lastStreak = 1;
  int xScore = 1;
  int oScore = 1;
  for(int i = 0; i < BOARD_COLS; i++)
  {
    for(int j = 0; j < BOARD_ROWS-1; j++)
    {
      //Pieces match
      if(board[j][i] != Blank && board[j][i] == board[j+1][i])
      {
        //three or more in a row
        if(lastPiece == board[j][i])
        {
          lastStreak++;
          if(board[j][i] == X && lastStreak > xScore)
          {
            xScore = lastStreak;
          }
          if(board[j][i] == O && lastStreak > oScore)
          {
            oScore = lastStreak;
          }
        }
        //two in a row
        // else
        // {
        //   if(board[j][i] == X && lastStreak > xScore)
        //   {
        //     xScore = 2;
        //   }
        //   if(board[j][i] == O && lastStreak > oScore)
        //   {
        //     oScore = 2;
        //   }
        //   lastStreak = 1;
        // }
        lastPiece = board[j][i];
      }
    }
    lastPiece = Invalid;
    lastStreak = 1;
  }

  for(int j = 0; j < BOARD_ROWS; j++)
  {
    for(int i = 0; i < BOARD_COLS-1; i++)
    {
      //Pieces match
      if(board[j][i] != Blank && board[j][i] == board[j][i+1])
      {
        //three or more in a row
        if(lastPiece == board[j][i])
        {
          lastStreak++;
          if(board[j][i] == X && lastStreak > xScore)
          {
            xScore = lastStreak;
          }
          if(board[j][i] == O && lastStreak > oScore)
          {
            oScore = lastStreak;
          }
        }
        //two in a row
        // else
        // {
        //   if(board[j][i] == X && lastStreak > xScore)
        //   {
        //     xScore = 2;
        //   }
        //   if(board[j][i] == O && lastStreak > oScore)
        //   {
        //     oScore = 2;
        //   }
        //   lastStreak = 1;
        // }
        lastPiece = board[j][i];
      }
    }
    lastPiece = Invalid;
    lastStreak = 1;
  }


  if(xScore > oScore)
  {
    return X;
  }
  else if(xScore < oScore)
  {
    return O;
  }
  else
  {
    return Blank;
  }

}
