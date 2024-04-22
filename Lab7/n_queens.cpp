 #include <iostream>
#include <vector>
using namespace std;
// Function to print the chessboard
void printBoard(const vector<vector<bool>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j]) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(const vector<vector<bool>>& board, int row, int col) {
    int N = board.size();

    // Check the column for any other queens
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j]) return false;
    }

    return true;
}

// Recursive backtracking function to solve N-Queens problem
void solveNQueensUtil(vector<vector<bool>>& board, int row) {
    int N = board.size();

    // Base case: If all queens are placed, print the board
    if (row == N) {
        printBoard(board);
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = true; // Place the queen

            // Recur to place queens in next row
            solveNQueensUtil(board, row + 1);

            board[row][col] = false; // Backtrack and remove the queen
        }
    }
}

// Function to solve N-Queens problem
void solveNQueens(int N) {
    // Create an empty chessboard
    vector<vector<bool>> board(N, vector<bool>(N, false));

    // Start with the first row
    solveNQueensUtil(board, 0);
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
