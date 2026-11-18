#ifndef NAIVE_H
#define NAIVE_H

#include <iostream>
#include <vector>
using namespace std;
#define N 9 //size

void printBoard(const vector<vector<int> >& board);
bool isSafe(const vector<vector<int> >& board, int row, int col, int num);
bool solveSudokuNaive(vector<vector<int> >& board);

#endif 
