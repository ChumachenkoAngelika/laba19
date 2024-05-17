#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../data_struct/string/processing_string.h"
#include "lab_20.h"
#define ASSERT_STRING_INT_ARR_CHAR_ARRAY(expectedInt, size_expectedInt, gotInt, size_gotInt, size_expecded_charArray, charArray_expected, size_got_charArray, charArray_got) assertStringIntArrAndStrArr(expectedInt, size_expectedInt, gotInt, size_gotInt, size_expecded_charArray, charArray_expected, size_got_charArray, charArray_got, __FILE__, __FUNCTION__, __LINE__);
void static printInt(int *arr, int size){    for(int i = 0; i < size;i++){
    fprintf(stderr,"%d ", arr[i]);    }
}
void print_char_array(int size, char array[size][1000]) {
    for (int i = 0; i < size; i++) {
        char *begin = array[i];
        while (*begin != '\0') {
            fprintf(stderr, "%c", *begin);
            begin++;
        }
        printf(" ");
    }
}

void assertStringIntArrAndStrArr(int *expectedInt, int size_expectedInt, int *gotInt, int size_gotInt, int size_charArr_expected, char charArr_expected[size_charArr_expected][1000], int size_charArr_got, char charArr_got[size_charArr_got][1000], char const *fileName, char const *funcName, int line) {
    bool flag = size_expectedInt == size_gotInt;
    if (flag) {
        for (int i = 0; i < size_gotInt; i++) {
            if (expectedInt[i] != gotInt[i]) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        flag = size_charArr_expected == size_charArr_got;
    }
    if (flag) {
        for (int i = 0; i < size_charArr_expected; i++) {
            if (!(strcmp_(charArr_expected[i], charArr_got[i]))) {
                flag = false;
                break;
            }
        }
    }
    if (!flag) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "expected: ");
        printInt(expectedInt, size_expectedInt);
        printf("\n");
        fprintf(stderr, "got: ");
        printInt(gotInt, size_gotInt);
        printf("\n");
        print_char_array(size_charArr_expected, charArr_expected);
        printf("\n");
        print_char_array(size_charArr_got, charArr_got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

void assertInt(int expected, int got, char const *fileName, char const *funcName, int line) {
    if (expected != got) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%d\"\n", expected);
        fprintf(stderr, "Got: \"%d\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

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


void testAll_liveGame() {
    int n = 4;
    int m = 3;
    int matrix[4][3] = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

    liveGame(*matrix, n, m);

    int resMatrix[4][3] = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    for (int z = 0; z < n; z++) {
        for (int x = 0; x < m; x++) {
            assert(matrix[z][x] == resMatrix[z][x]);
        }
    }
}




void tusk4_test1() {
    array_domain_count bag;
    char arr[][100] = {"9001 discuss.codeforces.com"};
    count_domain(arr, 1, &bag);
    int array_count_got[1000];
    char array_name_got[1000][1000];
    int size_array = 0;
    for (int i = 0; i < bag.size; i++) {
        char *begin = bag.array[i].name;
        copy(begin, begin + strlen_(begin), array_name_got[size_array]);
        array_count_got[size_array] = bag.array[size_array].data;
        size_array++;
    }
    int int_arr_expected[] = {9001, 9001, 9001};
    char char_arr_expected[][1000] = {"discuss.codeforces.com", "codeforces.com", "com"};
    ASSERT_STRING_INT_ARR_CHAR_ARRAY(int_arr_expected, 3, array_count_got, size_array, 3, char_arr_expected, size_array, array_name_got);
}

void tusk4_test2() {
    array_domain_count bag;
    char arr[][100] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    count_domain(arr, 4, &bag);
    int array_count_got[1000];
    char array_name_got[1000][1000];
    int size_array = 0;
    for (int i = 0; i < bag.size; i++) {
        char *begin = bag.array[i].name;
        copy(begin, begin + strlen_(begin), array_name_got[size_array]);
        array_count_got[size_array] = bag.array[size_array].data;
        size_array++;
    }
    int int_arr_expected[] = {900, 901, 951, 50, 1, 5, 5};
    char char_arr_expected[][1000] = {"google.mail.com", "mail.com", "com", "yahoo.com", "intel.mail.com", "wiki.org", "org"};
    ASSERT_STRING_INT_ARR_CHAR_ARRAY(int_arr_expected, 7, array_count_got, size_array, 7, char_arr_expected, size_array, array_name_got);
}


void tusk5_test1() {
    int arr[] = {10, 20, 30, 25, 25, 45, 15, 25, 35};
    matrix m = createMatrixFromArray(arr, 3, 3);
    median_filter(&m, 3);
    int res_arr[9];
    int size = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res_arr[size] = m.values[i][j];
            size++;
        }
    }
    int expected[] = {10, 20, 30, 25, 25, 45, 15, 25, 35};
    for (int i = 0; i < 9; i++) {
        assert(res_arr[i] == expected[i]);
    }
}

void tusk6_test1() {
    char *pattern = "IIIDIDDD";
    int size = strlen_(pattern) + 1;
    int arr[9] = {0};
    int bin_arr[9] = {1,1,1,1,1,1,1,1,1};
    bool flag = false;
    start_pattern_numb(pattern, 0, arr, bin_arr, &flag);
    int got_arr[size];
    for (int i = 0; i < size; i++) {
        got_arr[i] = arr[i];
    }
    int expected[] = {1,2,3,5,4,9,8,7,6};
    for (int i = 0; i < size; i++) {
        assert(expected[i] == got_arr[i]);
    }
}

void tusk6_test2() {
    char *pattern = "DDD";
    int size = strlen_(pattern) + 1;
    int arr[9] = {0};
    int bin_arr[9] = {1,1,1,1,1,1,1,1,1};
    bool flag = false;
    start_pattern_numb(pattern, 0, arr, bin_arr, &flag);
    int got_arr[size];
    for (int i = 0; i < size; i++) {
        got_arr[i] = arr[i];
    }
    int expected[] = {4,3,2,1};
    for (int i = 0; i < size; i++) {
        assert(expected[i] == got_arr[i]);
    }
}

void test_for_20laba(){
    test_1();
    test_2();
    test_3();
    test_4();
    testAll_liveGame();
    tusk4_test1();
    tusk4_test2();
    tusk5_test1();
    tusk6_test1();
    tusk6_test2();
}