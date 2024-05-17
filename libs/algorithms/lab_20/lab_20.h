

#ifndef PROJECT17_LAB_20_H
#define PROJECT17_LAB_20_H

#include "../../data_struct/matrix/matrix.h"
typedef struct domain_string_value {
    char name[1000];
    int data;
} domain_string_value;

typedef struct array_domain_count {
    int size;
    domain_string_value array[1000];
} array_domain_count;


#define MAX_N 100
#define ROWS 3
#define COLS 3

void updateMatrix(int matrix[MAX_N][MAX_N], int n, int query[][4], int len);

void printMatrix(int matrix[MAX_N][MAX_N], int n);

int countNeighbors(int *matrix, int n, int m, int col, int row);

void printMatrix(int matrix[MAX_N][MAX_N], int n);

void liveGame(int *matrix, size_t n, size_t m);

void medianFilter(int matrix[ROWS][COLS], int filter);

void add_in_array_domain_count(array_domain_count *bag, domain_string_value domain);

void count_search(char *string, char *res, int *size);
void median_filter(matrix *m, int filter);

#endif //PROJECT17_LAB_20_H
