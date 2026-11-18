#include "naive.h"

/* Function to print board */
void printBoard(const vector<vector<int> >& board)
{
    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

/* Check if safe to place in cell */
bool isSafe(const vector<vector<int> >& board, int row, int col, int num)
{
    for (int x = 0; x < N; x++) //check synchronously
    {
        if (board[row][x] == num){ //check row //x is col
            return false;
        }

        if (board[x][col] == num){ //check col //x is row
            return false;
        }

        if (board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num){ //check 3x3 sudgrid //x gives offset
            return false;
        }
    }
    return true; //safe
}

bool solveSudokuNaive(vector<vector<int> >& board)
{
    int row = -1;
    int col = -1;
    bool isEmpty = true; //empty cells left?

    for (int r = 0; r < N; r++){ //find empty cell
        for (int c = 0; c < N; c++){
            if (board[r][c] == 0) {
                row = r;
                col = c;
                isEmpty = false; //cell found
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) //solution found
    {
        return true; //solved
    }

    for (int num = 1; num <= 9; num++){ //try nums
        if (isSafe(board, row, col, num)){
            board[row][col] = num;
            if (solveSudokuNaive(board)){
                return true; //solution
            }
            board[row][col] = 0; //backtracking
        }
    }

    return false; //no solution
}