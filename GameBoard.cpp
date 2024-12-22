#include "GameBoard.h"
#include "GameBoard.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;

GameBoard::GameBoard(int n) : size(n), board(n* n)
{
    for (int i = 0; i < n * n; ++i) 
    {
        board[i] = to_string(i + 1);
    }
}

bool operator!=(const string& lhs, const char rhs) 
{
    return lhs != string(1, rhs);
}

void GameBoard::displayBoard() const 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            cout << setw(3) << board[i * size + j];
            if (j < size - 1)
            {
                cout << " |";
            }
        }
        cout << endl;
        if (i < size - 1) 
        {
            for (int j = 0; j < size; ++j) 
            {
                cout << "----";
            }
            cout << "-\n";
        }
    }
}

bool GameBoard::placeMarker(int position, char marker) 
{
    if (position < 1 || position > size * size) 
    {
        throw out_of_range("Invalid position");
    }
    if (board[position - 1] == "X" || board[position - 1] == "O") 
    {
        return false;
    }
    board[position - 1] = marker;
    return true;
}

bool GameBoard::checkWin(int sequenceLength, char marker) const
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            if (j <= size - sequenceLength) 
            {
                bool win = true;
                for (int k = 0; k < sequenceLength; ++k) 
                {
                    if (board[i * size + j + k] != marker) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
            if (i <= size - sequenceLength) 
            {
                bool win = true;
                for (int k = 0; k < sequenceLength; ++k) 
                {
                    if (board[(i + k) * size + j] != marker) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
            if (i <= size - sequenceLength && j <= size - sequenceLength) 
            {
                bool win = true;
                for (int k = 0; k < sequenceLength; ++k) 
                {
                    if (board[(i + k) * size + j + k] != marker) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
            if (i <= size - sequenceLength && j >= sequenceLength - 1) 
            {
                bool win = true;
                for (int k = 0; k < sequenceLength; ++k) {
                    if (board[(i + k) * size + j - k] != marker) 
                    {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }
    return false;
}

bool GameBoard::isFull() const 
{
    for (const auto& cell : board) 
    {
        if (cell != "X" && cell != "O")
        {
            return false;
        }
    }
    return true;
}


