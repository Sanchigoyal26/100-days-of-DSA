#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    char *start = str;
    char *end = str + strlen(str) - 1;

    int flag = 1;

    while(start < end) {
        if(*start != *end) {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if(flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}