#include <stdio.h>
#include "lab_20.h"


void updateMatrix(int matrix[MAX_N][MAX_N], int n, int query[][4], int len) {
    int i, j, k;
    for (k = 0; k < len; k++) {
        int row1 = query[k][0];
        int col1 = query[k][1];
        int row2 = query[k][2];
        int col2 = query[k][3];

        for (i = row1; i <= row2; i++) {
            for (j = col1; j <= col2; j++) {
                matrix[i][j]++;
            }
        }
    }
}

void printMatrix(int matrix[MAX_N][MAX_N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}




void gameOfLife(int** board, int boardSize, int* boardColSize){
    int m = boardSize;
    int n = *boardColSize;

    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int newBoard[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveCount = 0;

            for (int k = 0; k < 8; k++) {
                int x = i + directions[k][0];
                int y = j + directions[k][1];

                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] > 0) {
                    liveCount++;
                }
            }

            if (board[i][j] > 0) {
                if (liveCount < 2 || liveCount > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if (liveCount == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

