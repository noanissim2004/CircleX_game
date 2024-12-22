#include "TicTacToe.h"
#include "TicTacToe.h"
#include <stdexcept>
#include <iostream>
using namespace std;

TicTacToe::TicTacToe(int boardSize, int winCondition) : board(boardSize), winCondition(winCondition) 
{
    if (winCondition > boardSize) 
    {
        throw invalid_argument("Win condition cannot exceed board size");
    }
}


void TicTacToe::makeMove(int position, char marker) 
{
    if (marker != 'X' && marker != 'O') 
    {
        throw invalid_argument("Marker must be 'X' or 'O'");
    }
    if (!board.placeMarker(position, marker))
    {
        throw invalid_argument("Position already taken or invalid");
    }
    board.displayBoard();
    if (board.checkWin(winCondition, marker)) 
    {
        cout << "Player " << marker << " wins!" << endl;
        exit(0);
    }
    else if (board.isFull()) 
    {
        cout << "The game is a draw!" << endl;
        exit(0);
    }
    cout << endl << endl;
}

