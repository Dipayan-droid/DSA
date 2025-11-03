#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push value onto stack
void push(int val) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = val;
}

// Pop value from stack
int pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        return stack[top--];
    return -1;
}

// Calculate factorial using stack
int factorial(int n) {
    int result = 1;

    // Push all numbers from n down to 1 onto stack
    while (n > 1) {
        push(n);
        n--;
    }
    // Multiply all popped values to get factorial
    while (top != -1) {
        result *= pop();
    }
    return result;
}

int main() {
    int num, fact;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers!\n");
        return 1;
    }

    if (num == 0 || num == 1) {
        fact = 1;
    } else {
        fact = factorial(num);
    }

    printf("Factorial of %d is %d\n", num, fact);
    return 0;
}
