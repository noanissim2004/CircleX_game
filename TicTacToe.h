#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "GameBoard.h"

class TicTacToe 
{
private:
    GameBoard board;
    int winCondition;

public:
    TicTacToe(int boardSize, int winCondition);
    void makeMove(int position, char marker);
};

#endif // GAMEBOARD_H