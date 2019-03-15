/** Solve N-Queen problem
 *  with backtracking.
 */
#include <iostream>
#include <stdlib.h>

// Set the side of the board
// default: N = 5
#define N 4

// Return true if queen in [row], [col]
// isn't threatened by any existing queen.
bool isSafe(int board[N][N], const int& row, const int& col)
{
    // All the queens that have been placed will be in a
    // previous column than col.

    // Check every column in this row.
    int i, j;
    for (j = 0; j < col; j++) {
        if (board[row][j]) {
            return false;
        }
    }

    // Check every upper left diagonal tile.
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check every lower left diagonal tile.
    for (i = row + 1, j = col - 1; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQUtil(int board[N][N], const int& col)
{

    // If all the queens are placed,
    // return true
    if (col >= N) {
        return true;
    }

    // Check every row of this column.
    for (int i = 0; i < N; i++) {

        // Check if the queen can be placed in [i][col]
        if (isSafe(board, i, col)) {

            // Place the queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest queens
            if (solveNQUtil(board, col + 1)) {
                return true;
            }

            // If placing a queen in board[i][col] doesn't lead
            // to solution, the remove it from this tile *BACKTRACK*
            board[i][col] = 0;
        }
    }

    // If the queen can't be placed in any row
    // of this column, return false
    return false;
}

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << board[i][j] << " ";
        std::cout << "\n";
    }
}

// Set every tile to 0.
void initBoard(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
}

int main(int argc) {
    int board[N][N];

    std::cout << "Initializing board...\n";
    initBoard(board);
    std::cout << "Board initialised.\n";

    if (solveNQUtil(board, 0)) {
        std::cout << "\nThe queens have been placed in these places:\n";
        printSolution(board);
    } else {
        std::cout << "\nThe solution doesn't exist.\n";
    }


    system("pause");
    return 0;
}