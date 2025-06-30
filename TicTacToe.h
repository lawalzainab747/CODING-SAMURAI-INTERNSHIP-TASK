// TicTacToe.h

#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char human = 'X';
    char ai = 'O';

    int evaluate();
    bool isMovesLeft();
    int minimax(bool isMax);
    pair<int, int> findBestMove();
    bool checkWin(char player);

public:
    TicTacToe();
    void displayBoard();
    void playGame();
};

