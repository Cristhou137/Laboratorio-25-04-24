#include <iostream>
#include <vector>

using namespace std;

const int BOARD_SIZE = 8;

bool isSafe(int row, int col, const vector<vector<int>>& board) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < BOARD_SIZE; --i, ++j) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveEightQueens(int row, vector<vector<int>>& board) {
    if (row >= BOARD_SIZE)
        return true;

    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (isSafe(row, col, board)) {
            board[row][col] = 1;

            if (solveEightQueens(row + 1, board))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

    if (solveEightQueens(0, board)) {
        cout << "Solución encontrada: " << endl;
        printBoard(board);
    } else {
        cout << "Solución No encontrada: " << endl;
    }

    return 0;
}