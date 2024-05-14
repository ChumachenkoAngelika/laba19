#include <assert.h>
#include <stdio.h>
#include "lab_20.h"

void test_1(){
    int n = 3;
    int matrix[MAX_N][MAX_N] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    int queries[2][4] = {
            {1, 1, 2, 2},
            {0, 0, 1, 1}
    };

    updateMatrix(matrix, n, queries, 2);

    printf("Updated matrix:\n");
    printMatrix(matrix, n);

}
void test_2() {
    int n = 4;
    int matrix[MAX_N][MAX_N] = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
    };
    int queries[3][4] = {
            {0, 0, 3, 3},
            {1, 1, 2, 2},
            {2, 2, 3, 3}
    };

    updateMatrix(matrix, n, queries, 3);

    printf("Updated matrix:\n");
    printMatrix(matrix, n);
}

void test_3() {
    int n = 5;
    int matrix[MAX_N][MAX_N] = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
    };
    int queries[4][4] = {
            {0, 0, 4, 4},
            {0, 4, 4, 0},
            {4, 0, 0, 4},
            {2, 2, 2, 2}
    };

    updateMatrix(matrix, n, queries, 4);

    printf("Updated matrix:\n");
    printMatrix(matrix, n);
}

void test_4() {
    int n = 2;
    int matrix[MAX_N][MAX_N] = {
            {0, 0},
            {0, 0}
    };
    int queries[1][4] = {
            {0, 0, 1, 1}
    };

    updateMatrix(matrix, n, queries, 1);

    printf("Updated matrix:\n");
    printMatrix(matrix, n);
}


void test_5() {
        int n = 4;
        int m = 3;
        int matrix[4][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

        gameOfLife(*matrix, n, m);

        int resMatrix[4][3] = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
        for (int z = 0; z < n; z++) {
                for (int x = 0; x < m; x++) {
                        assert(matrix[z][x] == resMatrix[z][x]);
                }
        }

}







void testMedianFilter_1() {
        int matrix1[ROWS][COLS] = {
                {10, 20, 30},
                {25, 35, 45},
                {15, 25, 35}
        };
        int expected1[ROWS][COLS] = {
                {10, 20, 30},
                {25, 25, 45},
                {15, 25, 35}
        };
        medianFilter(matrix1, 3);
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        assert(matrix1[i][j] == expected1[i][j]);
                }
        }
}

void testMedianFilter_2() {
        int matrix3[ROWS][COLS] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        int expected3[ROWS][COLS] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        medianFilter(matrix3, 1);
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        assert(matrix3[i][j] == expected3[i][j]);
                }
        }

}

void testMedianFilter_3() {
        int matrix2[ROWS][COLS] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        int expected2[ROWS][COLS] = {
                {1, 2, 3},
                {2, 3, 4},
                {4, 5, 6}
        };
        medianFilter(matrix2, 2);
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        assert(matrix2[i][j] == expected2[i][j]);
                }
        }
}
void test_for_20laba(){
        test_1();
        test_2();
        test_3();
        test_4();
        test_5();
        testMedianFilter_1();
        testMedianFilter_2();
        testMedianFilter_3();
}