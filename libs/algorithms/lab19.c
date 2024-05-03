
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "io.h"
#include "../data_struct/matrix/matrix.h"
#include "../data_struct/string/string_.h"
#include "../data_struct/string/processing_string.h"
#include "../data_struct/string/tusk/test_processing_string.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__);
#define ASSERT_STRING_INT_ARR(expected, size_expected, got, size_got) assertStringIntArr(expected, size_expected, got, size_got, __FILE__, __FUNCTION__, __LINE__);
//tusk 1
void toColFromRow(FILE *file){
    char n_arr[100];
    fgets(n_arr, 100, file);
    char tempNumb[100];
    copy(n_arr, find(n_arr, n_arr+100, '\n')+1,tempNumb);
    replace(n_arr, "\n", "\0");
    int n = atoi(n_arr);
    int values[1000];
    int size = 0;
    while (feof(file)==0){
        const char numb = (char)fgetc(file);
        if(numb>='0' && numb <='9'){
            values[size] = atoi(&numb);
            size++;
        }
    }
    matrix matrix = createMatrixFromArray(values, n, size/n);
    transposeMatrix(&matrix);
    char result[size];
    int size_res = 0;
    for(int i = 0; i < size/n; i++){
        for(int j = 0; j < n; j++){
            result[size_res] = (char)(matrix.values[i][j] + 48);
            size_res++;
        }
        result[size_res] = '\n';
        size_res++;
    }
    fseek(file, 0l, 0);
    fputs(tempNumb, file);
    fputs(result, file);
}

void test1_tusk1(){
    char s[1000] = "4\n123456789\n963852741\n159236478\n951632874";
    FILE *file = fopen("my_file.txt", "w+");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,file);
    fseek(file,0l,0);
    toColFromRow(file);
    fclose(file);
    file = fopen("my_file.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("4\n1919\n2655\n3391\n4826\n5533\n6262\n7748\n8477\n9184\n",res)
    remove("my_file.txt");
}
void test2_tusk1(){
    char s[1000] = "5\n951632874\n789420000\n556236985\n123456789\n333333333";
    FILE *file = fopen("my_file.txt", "w+");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,file);
    fseek(file,0l,0);
    toColFromRow(file);
    fclose(file);
    file = fopen("my_file.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("5\n97513\n58523\n19633\n64243\n32353\n20663\n80973\n70883\n40593\n",res)
    remove("my_file.txt");
}
void test3_tusk1(){
    char s[1000] = "2\n951632874\n951632874";
    FILE *file = fopen("my_file.txt", "w+");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,file);
    fseek(file,0l,0);
    toColFromRow(file);
    fclose(file);
    file = fopen("my_file.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("2\n99\n55\n11\n66\n33\n22\n88\n77\n44\n",res)
    remove("my_file.txt");
}



void float_values(FILE *file){
    char values[1000];
    char arr_res[1000][1000];
    int size = 0;
    while(feof(file) == 0){
        if(fgets(values,1000, file)!=0) {
            *findSpaceReverse(values + strlen_(values) - 1, values) == '\n' ? *findSpaceReverse(
                    values + strlen_(values) - 1, values) = '\0' : *findSpaceReverse(values + strlen_(values) - 1,
                                                                                     values);
            char *point = find_symbl(values, '.');
            if (*point == '\0') {
                *point = '.';
                *(point + 1) = '0';
                *(point + 2) = '0';
                *(point + 3) = '\n';
                *(point + 4) = '\0';
            } else if (*point == '.' && *(point + 2) == '\0'){
                *(point + 2) = '0';
                *(point + 3) = '\n';
                *(point + 4) = '\0';
            } else {
                *(point + 3) = '\n';
                *(point + 4) = '\0';
            }
            *copy(values, strlen_(values)+values, arr_res[size]) = '\0';
            size++;
        }
    }
    fseek(file, 0L, 0);

    for(int i = 0; i < size; i++){
        char str[1000] = {0};
        char *begin = str;
        *copy(arr_res[i], arr_res[i]+ strlen_(arr_res[i]), begin) = '\0';
        fputs(str, file);
    }
    chsize(fileno(file), ftell(file));
}

void test1_tusk2(){
    char s[1000] = "159236478\n951632874\n323232.2535";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f,0L,0);
    float_values(f);
    fclose(f);
    FILE *file = fopen("my_file.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("159236478.00\n951632874.00\n323232.25\n",res)
    remove("my_file.txt");
}
void test2_tusk2(){
    char s[1000] = "159236478.1\n95.1632874\n323232";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f,0L,0);
    float_values(f);
    fclose(f);
    FILE *file = fopen("my_file.txt", "r");
    if(file==NULL) {
        printf("NULL");
        return;
    }
    char res[1000];
    int size = 0;
    while (feof(file)==0){
        res[size] = (char)(getc(file));
        size++;
    }
    res[size-1]='\0';
    fclose(file);
    ASSERT_STRING("159236478.10\n95.16\n323232.00\n",res)
    remove("my_file.txt");
}




void test_lab19() {
    test1_tusk1();
    test2_tusk1();
    test3_tusk1();
    test1_tusk2();
    test2_tusk2();
}
