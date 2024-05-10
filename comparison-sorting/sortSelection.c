void sortSelection(int arr[], int size) {
    int minValueIndex;

    for (int i = 0; i < size - 1; i++) {
        minValueIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minValueIndex]) {
                minValueIndex = j;
            }
        }
        int temp = arr[minValueIndex];
        arr[minValueIndex] = arr[i];
        arr[i] = temp;
    }
}
