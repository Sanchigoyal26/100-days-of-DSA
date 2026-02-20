#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// simple hashmap using array (for contest/college use)
long long countZeroSumSubarrays(int arr[], int n) {
    long long count = 0;
    long long prefixSum = 0;

    // frequency array (shifted index to handle negative sums)
    int size = 2 * MAX + 1;
    int *freq = (int*)calloc(size, sizeof(int));

    // prefix sum 0 initially appears once
    freq[MAX] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // shift index to avoid negative indexing
        int index = prefixSum + MAX;

        count += freq[index];
        freq[index]++;
    }

    free(freq);
    return count;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long result = countZeroSumSubarrays(arr, n);
    printf("Number of subarrays with sum 0 = %lld", result);

    return 0;
}