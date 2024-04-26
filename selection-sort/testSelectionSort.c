#include <stdio.h>
#include <stdbool.h>
#include <unity/unity.h>
#include "test_data_utils.h"
#include "selectionSort.h"

char TEST_DATA_FILE[] = "test1.txt";
bool DEBUG = true;
int SIZE = 50;

void setUp() {
    generate_test_data(TEST_DATA_FILE, SIZE, 1, 100);
}

void tearDown() {
    remove(TEST_DATA_FILE);
}

void testSelectionSort() {
    int *data = get_test_data(TEST_DATA_FILE);

    if (DEBUG) {
        printf("\n BEFORE SORT: ");
        for (int i = 0; data[i] != LAST_NUMBER; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    sortWithSelection(data, SIZE);

    if (DEBUG) {
        printf("\n AFTER SORT: ");
        for (int i = 0; data[i] != LAST_NUMBER; i++)   {
            printf("%d ", data[i]);
        }
        printf("\n");
    }

    for(int i = 0; data[i] != LAST_NUMBER; i++) {
        if (data[i+1] != LAST_NUMBER) {
            TEST_ASSERT_GREATER_OR_EQUAL(data[i], data[i+1]);
        }
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testSelectionSort);
    return UNITY_END();
}
