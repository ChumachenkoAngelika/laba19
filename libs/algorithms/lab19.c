
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


int doSolve(char s, int a, int b){
    if(s == '+')
        return a+b;
    else if(s == '-')
        return a-b;
    else if(s == '*')
        return a*b;
    else if(s == '/')
        return a/b;
    else if(s == '%')
        return a%b;
    fprintf(stderr, "Fail");
    return 0;
}

void arithmetic_solve(FILE *file){
    char data[10];
    fgets(data, 9, file);
    int a, b, c;
    a = atoi(&data[0]);
    b = atoi(&data[2]);
    c = atoi(&data[4]);
    int res = doSolve(data[1],a,b);
    res = doSolve(data[3], res, c);
    fputs("\n", file);
    char ans[4];
    char *begin = ans;
    if(0<=res && res <= 9){
        ans[0] = (char)(res + 48);
        *(begin+1) = '\0';
    }
    if(10<=res && res <= 99){
        ans[0] = (char)((res)/10 + 48);
        ans[1] = (char)((res)%10 + 48);
        *(begin+2) = '\0';
    }
    if(100<=res && res <= 729){
        ans[0] = (char)((res)/100 + 48);
        ans[1] = (char)((res/10)%10 + 48);
        ans[2] = (char)((res)%10 + 48);
        *(begin+3) = '\0';
    }
    if(0>res && res >= -9){
        res*=-1;
        ans[0] = '-';
        ans[1] = (char)(res + 48);
        *(begin+2) = '\0';
    }
    if(-10>=res && res >= -99){
        res*=-1;
        ans[0] = '-';
        ans[1] = (char)((res)/10 + 48);
        ans[2] = (char)((res)%10 + 48);
        *(begin+3) = '\0';
    }
    if(-100>=res && res >= -729){
        res*=-1;
        ans[0] = '-';
        ans[1] = (char)((res)/100 + 48);
        ans[2] = (char)((res/10)%10 + 48);
        ans[3] = (char)((res)%10 + 48);
        *(begin+4) = '\0';
    }
    fputs(ans, file);
}
void test1_tusk3(){
    char s[1000] = "1-5*3";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f, 0L, 0);
    arithmetic_solve(f);
    fclose(f);
    f = fopen("my_file.txt", "r");
    char ans[10];
    fgets(ans, 9, f);
    fgets(ans, 9, f);
    fclose(f);
    ASSERT_STRING("-12", ans)
    remove("my_file.txt");
}
void test2_tusk3(){
    char s[1000] = "9*9*3";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f, 0L, 0);
    arithmetic_solve(f);
    fclose(f);
    f = fopen("my_file.txt", "r");
    char ans[10];
    fgets(ans, 9, f);
    fgets(ans, 9, f);
    fclose(f);
    ASSERT_STRING("243", ans)
    remove("my_file.txt");
}
void test3_tusk3(){
    char s[1000] = "3+8%10";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f, 0L, 0);
    arithmetic_solve(f);
    fclose(f);
    f = fopen("my_file.txt", "r");
    char ans[10];
    fgets(ans, 9, f);
    fgets(ans, 9, f);
    fclose(f);
    ASSERT_STRING("1", ans)
    remove("my_file.txt");
}


void removeSomeStr(FILE *f, char *mask){
    char arr[100000];
    char *begin = arr;
    while (feof(f) == 0){
        char str[1000];
        char *beginStr = str;
        fgets(str, 1000, f);
        *find_symbl(str, '\n') = '\0';
        begin = copy(beginStr, beginStr+strlen_(str), begin);
        *begin = ' ';
        begin++;
    }
    *(begin-1) = '\0';
    BagOfWords words;
    getBagOfWords(&words, arr);
    char res_arr[100000];
    char *begin_res = res_arr;
    int countSpase = 0;
    for(int i = 0; i < words.size; i++){
        if(mask_in_str(&words.words[i], mask)){
            countSpase++;
            begin_res = copy(words.words[i].begin, words.words[i].end, begin_res);
            if(countSpase == 7){
                countSpase = 0;
                *begin_res = '\n';
            } else
                *begin_res = ' ';
            begin_res++;

        }
    }
    words.size = 0;
    *(begin_res-1) = '\n';
    *(begin_res) = '\0';
    fseek(f, 0L, 0);
    fputs(res_arr, f);
    chsize(fileno(f), ftell(f));
}
void test1_tusk4(){
    char s[10000] = "asdf ggasfasf elmberr\nekoveuv ejweuvr erwcvuiev";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f, 0L, 0);
    removeSomeStr(f, "e");
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
    ASSERT_STRING("elmberr ekoveuv ejweuvr erwcvuiev\n", res)
    remove("my_file.txt");
}
void test2_tusk4(){
    char s[10000] = "ggasefasfffff aesdf ggasefasf elmberr\nekoveuv ejweuvr erwhcvuiev daverwer homE verte\newegvsdv egvwvsdv";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f, 0L, 0);
    removeSomeStr(f, "e");
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
    ASSERT_STRING("ggasefasfffff aesdf ggasefasf elmberr ekoveuv ejweuvr erwhcvuiev\ndaverwer verte ewegvsdv egvwvsdv\n", res);
    remove("my_file.txt");
}
void test3_tusk4(){
    char s[10000] = "ggasefasfffff aesdf\nggasefasf elmberr\nekoveuv ejweuvr\nerwhcvuiev daverwer homE verte\newegvsdv egvwvsdv";
    FILE *f = fopen("my_file.txt", "w+");
    if(f==NULL) {
        printf("NULL");
        return;
    }
    fputs(s,f);
    fseek(f, 0L, 0);
    removeSomeStr(f, "e");
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
    ASSERT_STRING("ggasefasfffff aesdf ggasefasf elmberr ekoveuv ejweuvr erwhcvuiev\ndaverwer verte ewegvsdv egvwvsdv\n", res);
    remove("my_file.txt");
}


void test_lab19() {
    test1_tusk1();
    test2_tusk1();
    test3_tusk1();
    test1_tusk2();
    test2_tusk2();
    test1_tusk3();
    test2_tusk3();
    test3_tusk3();
    test1_tusk4();
    test2_tusk4();
    test3_tusk4();

}
