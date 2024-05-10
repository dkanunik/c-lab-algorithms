void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void sortQuick(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        sortQuick(arr, low, pi - 1);
        sortQuick(arr, pi + 1, high);
    }
}