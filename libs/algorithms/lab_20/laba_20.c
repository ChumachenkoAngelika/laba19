#include <stdbool.h>
#include <stdio.h>
#include "lab_20.h"

#include "../../data_struct/string/processing_string.h"
#include "../../data_struct/matrix/matrix.h"
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
int countNeighbors(int *matrix, int n, int m, int col, int row) {
    int (*tempMatrix)[m] = (int (*)[m])matrix;
    int row1 = row - 1;
    int row2 = row + 1;
    int col1 = col - 1;
    int col2 = col + 1;

    row1 = row1 < 0 ? 0 : row1;
    row2 = row2 >= n ? n - 1 : row2;
    col1 = col1 < 0 ? 0 : col1;
    col2 = col2 >= m ? m - 1 : col2;

    int counter = 0;
    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if ((i == row) && (j == col)) {
                continue;
            }

            counter += tempMatrix[i][j];
        }
    }
    return counter;
}

void liveGame(int *matrix, size_t n, size_t m) {
    int (*tempMatrix)[m] = (int (*)[m])matrix;
    int sums[n][m];
    int (*tempMatrix1)[m] = (int (*)[m])sums;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int res = countNeighbors(matrix, n,  m, col, row);
            sums[row][col] = res;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tempMatrix[i][j] == 1 && tempMatrix1[i][j] < 2) {
                tempMatrix[i][j] = 0;
            }
            if (tempMatrix[i][j] == 1 && (tempMatrix1[i][j] == 2 || tempMatrix1[i][j] == 3)) {
                tempMatrix[i][j] = 1;
            }
            if (tempMatrix[i][j] == 1 && tempMatrix1[i][j] > 3) {
                tempMatrix[i][j] = 0;
            }
            if (tempMatrix[i][j] == 0 && tempMatrix1[i][j] == 3) {
                tempMatrix[i][j] = 1;
            }
        }
    }
}



void medianFilter(int matrix[ROWS][COLS], int filter) {
    int temp[filter * filter];
    int half = filter / 2;

    for (int i = half; i < ROWS - half; i++) {
        for (int j = half; j < COLS - half; j++) {
            int k = 0;
            for (int x = i - half; x <= i + half; x++) {
                for (int y = j - half; y <= j + half; y++) {
                    temp[k++] = matrix[x][y];
                }
            }
            for (int p = 0; p < filter * filter - 1; p++) {
                for (int q = 0; q < filter * filter - p - 1; q++) {
                    if (temp[q] > temp[q+1]) {
                        int a = temp[q];
                        temp[q] = temp[q+1];
                        temp[q+1] = a;
                    }
                }
            }
            matrix[i][j] = temp[filter * filter / 2];
        }
    }
}



void add_in_array_domain_count(array_domain_count *bag, domain_string_value domain) {
    bool flag_new = true;
    if (bag->size != 0) {
        for (int i = 0; i < bag->size; i++) {
            if (strcmp_(bag->array[i].name, domain.name)) {
                bag->array[i].data += domain.data;
                flag_new = false;
            }
        }
    }
    if (flag_new) {
        char *begin = domain.name;
        *copy(begin, begin + strlen_(begin), bag->array[bag->size].name) = '\0';
        bag->array[bag->size].data = domain.data;
        bag->size++;
    }
}

void count_search(char *string, char *res, int *size) {
    char *begin = string;
    while (*begin != '\0') {
        if (*begin >= '0' && *begin <= '9') {
            res[*size] = *begin;
            (*size)++;
            begin++;
        } else {
            res[*size] = '\0';
            *size += 1;
            return;
        }
    }
}


void median_filter(matrix *m, int filter) {
    int temp[filter * filter];
    int half = filter / 2;

    for (int i = half; i < m->nRows - half; i++) {
        for (int j = half; j < m->nCols - half; j++) {
            int k = 0;
            for (int x = i - half; x <= i + half; x++) {
                for (int y = j - half; y <= j + half; y++) {
                    temp[k++] = m->values[x][y];
                }
            }
            for (int p = 0; p < filter * filter - 1; p++) {
                for (int q = 0; q < filter * filter - p - 1; q++) {
                    if (temp[q] > temp[q+1]) {
                        int a = temp[q];
                        temp[q] = temp[q+1];
                        temp[q+1] = a;
                    }
                }
            }
            m->values[i][j] = temp[filter * filter / 2];
        }
    }
}



