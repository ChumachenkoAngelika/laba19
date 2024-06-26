

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


typedef struct list{
    int data;
    struct list *left;
    struct list *right;
    int neighbour;
}list;


list static *creat_list(int data){
    list *node = malloc(sizeof(list));
    node->data = data;
    node->neighbour=0;
    return node;
}
#define MAX_N 100
#define ROWS 3
#define COLS 3

void updateMatrix(int matrix[MAX_N][MAX_N], int n, int query[][4], int len);

void printMatrix(int matrix[MAX_N][MAX_N], int n);

int countNeighbors(int *matrix, int n, int m, int col, int row);

void printMatrix(int matrix[MAX_N][MAX_N], int n);

void liveGame(int *matrix, size_t n, size_t m);

void medianFilter(int matrix[ROWS][COLS], int filter);
void count_domain(char (*arr)[100], int size, array_domain_count *bag_domain) ;

char* point_in_string(const char* str);

void add_in_array_domain_count(array_domain_count *bag, domain_string_value domain);

void count_search(char *string, char *res, int *size);


void median_filter(matrix *m, int filter);



int sumOfValueArray(int *a, int size);

void end_pattern_numb(const char *pattern, int cur, int *arr, int *bin_arr,bool *flag_end);

void start_pattern_numb(const char *pattern, int cur, int *arr, int *bin_arr, bool *flag_end);


list *push_list(int data, int flag, list *node);

int find_indx_maxValue_border(int *arr, int border_left, int border_right);

void trees(int *arr, int border_left, int border_right, list *tree, int max_size_arr);

void BFS_list(list *tree[1000], int size, int *arr_res, int  *res_size);


void change_letters(int *arr, char *s);

void make_file(FILE *f, int N);

char *find_suffix(char *s);



#endif //PROJECT17_LAB_20_H
