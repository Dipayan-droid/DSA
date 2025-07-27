#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++)
        stack[++top] = str[i];

    for (int i = 0; i < len; i++)
        str[i] = stack[top--];
}

int main() {
    char str[100];
    printf("Enter string: ");
    gets(str);

    reverseString(str);
    printf("Reversed: %s\n", str);
    return 0;
}
