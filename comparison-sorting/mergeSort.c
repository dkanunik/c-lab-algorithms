void merge(int arr[], int leftElementIndex, int midElementIndex, int rightElementIndex) {
    int leftArrCounter;
    int rightArrCounter;
    int mergeCounter;

    int leftArrSize = midElementIndex - leftElementIndex + 1;
    int rightArrSize = rightElementIndex - midElementIndex;

    int leftArr[leftArrSize];
    int rightArr[rightArrSize];

    for (leftArrCounter = 0; leftArrCounter < leftArrSize; leftArrCounter++) {
        leftArr[leftArrCounter] = arr[leftElementIndex + leftArrCounter];
    }

    for (rightArrCounter = 0; rightArrCounter < rightArrSize; rightArrCounter++) {
        rightArr[rightArrCounter] = arr[midElementIndex + 1 + rightArrCounter];
    }

    leftArrCounter = 0;
    rightArrCounter = 0;
    mergeCounter = leftElementIndex;

    while (leftArrCounter < leftArrSize && rightArrCounter < rightArrSize) {
        if (leftArr[leftArrCounter] <= rightArr[rightArrCounter]) {
            arr[mergeCounter] = leftArr[leftArrCounter];
            leftArrCounter++;
        } else {
            arr[mergeCounter] = rightArr[rightArrCounter];
            rightArrCounter++;
        }
        mergeCounter++;
    }

    while (leftArrCounter < leftArrSize) {
        arr[mergeCounter] = leftArr[leftArrCounter];
        leftArrCounter++;
        mergeCounter++;
    }

    while (rightArrCounter < rightArrSize) {
        arr[mergeCounter] = rightArr[rightArrCounter];
        rightArrCounter++;
        mergeCounter++;
    }
}

void sortWithMerge(int arrToSort[], int leftElementIndex, int rightElementIndex) {
    if (leftElementIndex < rightElementIndex) {
        int midElementIndex = leftElementIndex + (rightElementIndex - leftElementIndex) / 2;

        sortWithMerge(arrToSort, leftElementIndex, midElementIndex);
        sortWithMerge(arrToSort, midElementIndex + 1, rightElementIndex);

        merge(arrToSort, leftElementIndex, midElementIndex, rightElementIndex);
    }
}