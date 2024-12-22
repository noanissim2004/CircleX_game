#include "GameBoard.h"
#include "TicTacToe.h"
#include <iostream>
#include <stdexcept>
#include <iostream>
using namespace std;

int main() 
{
    try 
    {
        TicTacToe game(4, 4);

        game.makeMove(1, 'X');
        game.makeMove(2, 'O');
        game.makeMove(5, 'X');
        game.makeMove(6, 'O');
        game.makeMove(9, 'X');
        game.makeMove(10, 'O');

        return 0;
    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
