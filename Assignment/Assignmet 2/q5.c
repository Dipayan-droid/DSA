#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *text) {
    int len = strlen(text);
    char clean[1000];
    int idx = 0;

    for (int i = 0; i < len; i++)
        if (isalnum(text[i]))
            clean[idx++] = tolower(text[i]);

    clean[idx] = '\0';

    for (int i = 0; i < idx / 2; i++)
        if (clean[i] != clean[idx - i - 1])
            return false;

    return true;
}

int main() {
    char str[1000];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    if (is_palindrome(str))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
