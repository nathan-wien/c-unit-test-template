#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add.h"
#include "concat.h"
#include "mergeSort.h"

void setUp() {
    // set stuff up here
}

void tearDown() {
    // clean stuff up here
}

typedef struct {
    int a[100];
    int n;
} Array;

Array readArray(const char* path) {
    FILE* fp = fopen(path, "r");
    Array arr;
    fscanf(fp, "%d", &arr.n);
    for (int i = 0; i < arr.n; i++) {
        fscanf(fp, "%d", &arr.a[i]);
    }
    fclose(fp);
    return arr;
}

// each test function must starts with "test_"
void test_add() {
    TEST_ASSERT_EQUAL_INT32(5, add(2, 3));
}

void test_mergeSort() {
    int b[] = {5, 3, 1, 4, 2};
    int b_sorted[] = {1, 2, 3, 4, 5};
    mergeSort(b, 0, 4);
    TEST_ASSERT_EQUAL_INT32_ARRAY(b_sorted, b, 5);
}

void test_mergeSort2() {
    Array arr = readArray("mergeSort.in");
    int b_sorted[] = {1, 2, 3, 4, 5};
    mergeSort(arr.a, 0, 4);
    TEST_ASSERT_EQUAL_INT32_ARRAY(b_sorted, arr.a, 5);
}
