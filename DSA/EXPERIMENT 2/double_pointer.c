#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;
    int **q = &p;

    printf("Value of x = %d\n", **q);
    return 0;
}