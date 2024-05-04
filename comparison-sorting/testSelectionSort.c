#include <stdio.h>
#include <stdlib.h>
#include <unity/unity.h>
#include "testDataUtils.h"
#include "comparisonSorting.h"

char *testDataFileName = NULL;
int *testData = NULL;

void setUp() {
    testDataFileName = generateRandomString(5);
    int result = generateTestData(testDataFileName, 1, 500);
    if (result != 0) {
        perror("Error generating test data");
        exit(EXIT_FAILURE);
    }
    testData = getTestData(testDataFileName);
}

void tearDown() {
    removeTestDataFile(testDataFileName);
    testDataFileName = NULL;
    testData = NULL;
}

void testBubbleSort() {

    sortWithBubble(testData, MAX_DATA_SIZE);
    for (int i = 0; testData[i] != LAST_NUMBER; i++) {
        if (testData[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(testData[i], testData[i + 1]);
        }
    }
}

void testSelectionSort() {
    sortWithSelection(testData, MAX_DATA_SIZE);
    for (int i = 0; testData[i] != LAST_NUMBER; i++) {
        if (testData[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(testData[i], testData[i + 1]);
        }
    }
}

void testInsertionSort() {
    sortWithInsertion(testData, MAX_DATA_SIZE);
    for (int i = 0; testData[i] != LAST_NUMBER; i++) {
        if (testData[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(testData[i], testData[i + 1]);
        }
    }
}

void testShellSort() {
    sortWithShell(testData, MAX_DATA_SIZE);
    for (int i = 0; testData[i] != LAST_NUMBER; i++) {
        if (testData[i + 1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(testData[i], testData[i + 1]);
        }
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testBubbleSort);
    RUN_TEST(testSelectionSort);
    RUN_TEST(testInsertionSort);
    RUN_TEST(testShellSort);
    return UNITY_END();
}
