#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class GameBoard
{
private:
    int size;
    vector<string> board;
public:
    GameBoard(int n);
    friend bool operator!=(const std::string& lhs, const char rhs);
    void displayBoard() const;
    bool placeMarker(int position, char marker);
    bool checkWin(int sequenceLength, char marker) const;
    bool isFull() const;
};
#endif // GAMEBOARD_H
