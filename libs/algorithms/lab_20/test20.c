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

void test_for_20laba(){
    test_1();
    test_2();
    test_3();
    test_4();
}