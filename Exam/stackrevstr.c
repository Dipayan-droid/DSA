#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push character onto stack
void push(char ch) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = ch;
}

// Pop character from stack
char pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        return stack[top--];
    return '\0';
}

// Reverse a string using stack
void reverse(char str[]) {
    int len = strlen(str);
    top = -1; // Reset stack for reuse
    // Push all characters onto stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    // Pop characters to form reversed string
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    // Remove newline if present
    size_t ln = strlen(str) - 1;
    if (str[ln] == '\n') str[ln] = '\0';

    reverse(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
