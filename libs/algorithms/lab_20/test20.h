

#ifndef PROJECT17_TEST20_H
#define PROJECT17_TEST20_H
#include <stdbool.h>
#include "../../data_struct/string/processing_string.h"

#define ASSERT_STRING_INT_ARR(expected, size_expected, got, size_got) assertStringIntArr(expected, size_expected, got, size_got, __FILE__, __FUNCTION__, __LINE__);
#define ASSERT_STRING_INT_ARR_CHAR_ARRAY(expectedInt, size_expectedInt, gotInt, size_gotInt, size_expecded_charArray, charArray_expected, size_got_charArray, charArray_got) assertStringIntArrAndStrArr(expectedInt, size_expectedInt, gotInt, size_gotInt, size_expecded_charArray, charArray_expected, size_got_charArray, charArray_got, __FILE__, __FUNCTION__, __LINE__);
typedef struct domain_string_value {
    char name[1000];
    int data;
} domain_string_value;

typedef struct array_domain_count {
    int size;
    domain_string_value array[1000];
} array_domain_count;

void test_for_20laba();
#endif //PROJECT17_TEST20_H
