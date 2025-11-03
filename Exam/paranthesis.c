#include <stdio.h>
#include <string.h>
#define MAX 100

int top = -1;
char stk[MAX];

void push(char c) {
    if(top == (MAX - 1))
        printf("Stack Overflow\n");
    else
        stk[++top] = c;
}

char pop() {
    if(top == -1)
        printf("Stack Underflow\n");
    else
        return stk[top--];
    return '\0';
}

int main() {
    char exp[MAX], temp;
    int i, flag = 1;  // Assume valid
    printf("Enter an expression: ");
    gets(exp); // Use fgets in actual practice

    for(i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(top == -1)
                flag = 0;
            else {
                temp = pop();
                if(exp[i] == ')' && (temp == '{' || temp == '['))
                    flag = 0;
                if(exp[i] == '}' && (temp == '(' || temp == '['))
                    flag = 0;
                if(exp[i] == ']' && (temp == '(' || temp == '{'))
                    flag = 0;
            }
        }
    }
    if(top >= 0)
        flag = 0;
    if(flag == 1)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");
    return 0;
}
