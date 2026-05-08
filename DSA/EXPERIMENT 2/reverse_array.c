#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    int *ptr = arr + n - 1;

    for(int i = 0; i < n; i++) {
        printf("%d ", *ptr);
        ptr--;
    }
    return 0;
}