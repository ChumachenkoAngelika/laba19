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


void count_domain(char (*arr)[100], int size, array_domain_count *bag_domain) {
    bag_domain->size = 0;
    for (int i = 0; i < size; i++) {
        char count_str[100];
        char *begin = arr[i];
        int shift = 0;
        count_search(begin, count_str, &shift);
        int count = atoi(count_str);
        begin += shift;
        while (point_in_string(begin - 1)) {
            domain_string_value data_domain;
            data_domain.data = count;
            char *copy_in = data_domain.name;
            *copy(begin, begin + strlen_(begin), copy_in) = '\0';
            add_in_array_domain_count(bag_domain, data_domain);
            begin = find_symbl(begin, '.');
            begin++;
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


int sumOfValueArray(int *a, int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum+=a[i];
    return sum;
}

void end_pattern_numb(const char *pattern, int cur, int *arr, int *bin_arr,bool *flag_end){

    for (int i = 1; i <= 9; i++) {
        if(cur == strlen_(pattern)){
            *flag_end = true;
            return;
        }
        if (bin_arr[i - 1] == 1) {
            arr[cur+1] = i;
            bin_arr[i - 1] = 0;
            if (pattern[cur] == 'I' && arr[cur] < arr[cur+1]) {
                end_pattern_numb(pattern, cur + 1, arr, bin_arr,flag_end);
                if(sumOfValueArray(bin_arr, 9) == 0){
                    *flag_end = true;
                    return;
                }
            }
            else if (pattern[cur] == 'D' && arr[cur] > arr[cur+ 1]) {
                end_pattern_numb(pattern, cur + 1, arr, bin_arr, flag_end);
                if(sumOfValueArray(bin_arr, 9) == 0){
                    *flag_end = true;
                    return;
                }
            }
            if(*flag_end){
                return;
            }
            bin_arr[i - 1] = 1;

        }
    }

}
void start_pattern_numb(const char *pattern, int cur, int *arr, int *bin_arr, bool *flag_end) {
    for (int i = 1; i < 10; i++) {
        arr[cur] = i;
        bin_arr[i - 1] = 0;
        end_pattern_numb(pattern, cur, arr, bin_arr, flag_end);
        if(*flag_end){
            return;
        }
        bin_arr[i - 1] = 1;
    }
}


list *push_list(int data, int flag, list *node){
    node->data = data;
    list *temp = creat_list(0);
    if(flag == 0){
        node->left = temp;
        if(node->neighbour == 0){
            node->neighbour = 1;
        } else{
            node->neighbour = 3;
        }
    } else{
        node->right = temp;
        if(node->neighbour == 0){
            node->neighbour = 2;
        } else{
            node->neighbour = 3;
        }
    }
    return temp;
}
int find_indx_maxValue_border(int *arr, int border_left, int border_right){
    int max_value = INT_MIN;
    int indx;
    for(int i = border_left; i < border_right; i++){
        if(max_value < arr[i]){
            max_value = arr[i];
            indx = i;
        }
    }
    return indx;
}
void trees(int *arr, int border_left, int border_right, list *tree, int max_size_arr){
    if(border_right == border_left) {
        return;
    }
    int max_index = find_indx_maxValue_border(arr, border_left,border_right);
    if(max_index != border_left) {
        trees(arr, border_left, max_index, push_list(arr[max_index], 0, tree),max_size_arr);
        if(border_right - border_left == 1)
            tree->neighbour=0;
    }
    if(max_index != border_right && max_index+1 != max_size_arr ||  border_right-border_left==1) {
        trees(arr, max_index + 1, border_right, push_list(arr[max_index], 1, tree),max_size_arr);
        if(border_right - border_left == 1)
            tree->neighbour=0;
    }
}
void BFS_list(list *tree[1000], int size, int *arr_res, int  *res_size){
    int temp_size = 0;
    list *tempArr[1000];
    for(int i = 0; i < size; i++){
        arr_res[*res_size] = tree[i]->data;
        (*res_size)++;
        if(tree[i]->neighbour == 1){
            tempArr[temp_size] = tree[i]->left;
            temp_size++;
        }
        if(tree[i]->neighbour == 2){
            tempArr[temp_size] = tree[i]->right;
            temp_size++;
        }
        if(tree[i]->neighbour == 3){
            tempArr[temp_size] = tree[i]->left;
            temp_size++;
            tempArr[temp_size] = tree[i]->right;
            temp_size++;
        }
        tree[i]->neighbour=0;
        if(size>1)
            free(tree[i]);
        if(size == 1)
            tree[0]->neighbour=0;

    }
    if(temp_size == 0)
        return;
    BFS_list(tempArr, temp_size, arr_res, res_size);

}

void change_letters(int *arr, char *s){
    int size_s = strlen_(s);
    char temp_string[size_s+1];
    for(int i = 0; i < size_s; i++){
        *(temp_string+arr[i]) = *(s+i);
    }
    for (int i = 0; i < size_s; i++) {
        *(s+i )= *(temp_string+i);
    }
}
