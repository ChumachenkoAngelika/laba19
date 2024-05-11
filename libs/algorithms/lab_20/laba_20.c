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