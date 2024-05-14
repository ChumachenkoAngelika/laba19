

#ifndef PROJECT17_LAB_20_H
#define PROJECT17_LAB_20_H
#define MAX_N 100
#define ROWS 3
#define COLS 3

void updateMatrix(int matrix[MAX_N][MAX_N], int n, int query[][4], int len);

void printMatrix(int matrix[MAX_N][MAX_N], int n);

void gameOfLife(int** board, int boardSize, int* boardColSize);

void medianFilter(int matrix[ROWS][COLS], int filter);
#endif //PROJECT17_LAB_20_H
