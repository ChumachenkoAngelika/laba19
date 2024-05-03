//
// Created by admin on 10.04.2024.
//


#ifndef PROJECT17_TEST_PROCESSING_STRING_H
#define PROJECT17_TEST_PROCESSING_STRING_H
void test_lab18();

void assertString(const char *expected, char *got, char const *fileName, char const *funcName,int line);

void assertStringIntArr(int *expected, int size_expected, int *got,int size_got, char const *fileName, char const *funcName, int line);
#endif //PROJECT17_TEST_PROCESSING_STRING_H
