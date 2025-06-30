// TicTacToe.cpp
#include "TicTacToe.h"
#include <limits>

TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void TicTacToe::displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool TicTacToe::isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

int TicTacToe::evaluate() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            if (board[i][0] == ai) return +10;
            if (board[i][0] == human) return -10;
        }

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            if (board[0][i] == ai) return +10;
            if (board[0][i] == human) return -10;
        }
    }

    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == ai) return +10;
        if (board[0][0] == human) return -10;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == ai) return +10;
        if (board[0][2] == human) return -10;
    }

    return 0;
}

int TicTacToe::minimax(bool isMax) {
    int score = evaluate();
    if (score == 10 || score == -10)
        return score;
    if (!isMovesLeft())
        return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') {
                    board[i][j] = ai;
                    best = max(best, minimax(false));
                    board[i][j] = ' ';
                }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') {
                    board[i][j] = human;
                    best = min(best, minimax(true));
                    board[i][j] = ' ';
                }
        return best;
    }
}

pair<int, int> TicTacToe::findBestMove() {
    int bestVal = -1000;
    pair<int, int> bestMove = { -1, -1 };

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                int moveVal = minimax(false);
                board[i][j] = ' ';
                if (moveVal > bestVal) {
                    bestMove = { i, j };
                    bestVal = moveVal;
                }
            }

    return bestMove;
}

bool TicTacToe::checkWin(char player) {
    return evaluate() == (player == ai ? 10 : -10);
}

void TicTacToe::playGame() {
    cout << "You are X, Computer is O.\n";
    displayBoard();

    while (true) {
        int row, col;
        cout << "Enter your move (1-3 row and 1-3 col): ";
        cin >> row >> col;
        row--; col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            board[row][col] = human;
        else {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        displayBoard();

        if (checkWin(human)) {
            cout << "You win!\n";
            break;
        }

        if (!isMovesLeft()) {
            cout << "It's a tie!\n";
            break;
        }

        cout << "Computer is making a move...\n";
        pair<int, int> aiMove = findBestMove();
        board[aiMove.first][aiMove.second] = ai;

        displayBoard();

        if (checkWin(ai)) {
            cout << "Computer wins!\n";
            break;
        }

        if (!isMovesLeft()) {
            cout << "It's a tie!\n";
            break;
        }
    }
}
