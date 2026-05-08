#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;      // left child (0-based)
    int right = 2 * i + 2;     // right child (0-based)
    int temp;

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;

    // Build max heap (rearrange array)
    // Start from last non-leaf node down to root
    for (i = n / 2 - 1; i >= 0; i--) {  //for zero index start with last parent node
        heapify(arr, n, i);
    }

    // Extract elements one by one from heap
    for (i = n - 1; i > 0; i--) {
        // Move current root to end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Zero-indexed array - no dummy element needed
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;  // Number of elements

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}