#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <stdbool.h>

#ifdef DEBUG
    #undef DEBUG
#endif

#define DEBUG false

void sortWithSelection(int arr[], int size);
void sortWithInsertion(int arr[], int size);
void sortWithBubble(int arr[], int size);
void sortWithShell(int arr[], int size);

#endif //SELECTION_SORT_H
