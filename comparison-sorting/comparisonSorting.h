#ifndef COMPARISON_SORTING_H
#define COMPARISON_SORTING_H

#include <stdbool.h>

#ifdef DEBUG
    #undef DEBUG
#endif

#define DEBUG false

void sortSelection(int arr[], int size);
void sortInsertion(int arr[], int size);
void sortBubble(int arr[], int size);
void sortShell(int arr[], int size);
void sortMerge(int arr[], int l, int r);
void sortQuick(int arr[], int low, int high);

#endif //COMPARISON_SORTING_H
