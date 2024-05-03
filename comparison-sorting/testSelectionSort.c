#include <stdio.h>
#include <stdlib.h>
#include <unity/unity.h>
#include "testDataUtils.h"
#include "comparisonSorting.h"

char *testDataFileName = NULL;

void setUp() {
    testDataFileName = generateRandomString(5);
    int result = generateTestData(testDataFileName, 1, 500);
    if (result != 0) {
        perror("Error generating test data");
        exit(EXIT_FAILURE);
    }
}

void tearDown() {
    removeTestDataFile(testDataFileName);
    testDataFileName = NULL;
}

void testBubbleSort() {
    int *data = getTestData(testDataFileName);
    sortWithBubble(data, MAX_DATA_SIZE);
    for (int i = 0; data[i] != LAST_NUMBER; i++) {
        if (data[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(data[i], data[i + 1]);
        }
    }
}

void testSelectionSort() {
    int *data = getTestData(testDataFileName);
    sortWithSelection(data, MAX_DATA_SIZE);
    for (int i = 0; data[i] != LAST_NUMBER; i++) {
        if (data[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(data[i], data[i + 1]);
        }
    }
}

void testInsertionSort() {
    int *data = getTestData(testDataFileName);
    sortWithInsertion(data, MAX_DATA_SIZE);
    for (int i = 0; data[i] != LAST_NUMBER; i++) {
        if (data[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(data[i], data[i + 1]);
        }
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testBubbleSort);
    RUN_TEST(testSelectionSort);
    RUN_TEST(testInsertionSort);
    return UNITY_END();
}
