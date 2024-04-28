#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 8;

bool isSafe(int row, int col, const vector<int>& board) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(i - row) == abs(board[i] - col))
            return false;
    }
    return true;
}

void printBoard(const vector<int>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i] == j) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

bool solveEightQueensRandom(vector<int>& board) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, BOARD_SIZE - 1);

    for (int row = 0; row < BOARD_SIZE; ++row) {
        int col = dis(gen);
        board[row] = col;
        if (!isSafe(row, col, board)) {
            // Reset board and start over
            fill(board.begin(), board.end(), -1);
            row = -1;  // Reset row to start over from the beginning
        }
    }

    return true;
}

int main() {
    vector<int> board(BOARD_SIZE, -1);

    if (solveEightQueensRandom(board)) {
        cout << "Solución encontrada: " << endl;
        printBoard(board);
    } else {
        cout << "Solución No encontrada." << endl;
    }

    return 0;
}
