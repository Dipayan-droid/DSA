#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

char st[MAX];
int top = -1;

void push(char st[], char val) {
    if (top == MAX - 1)
        printf("\nSTACK OVERFLOW");
    else
        st[++top] = val;
}

char pop(char st[]) {
    char val = ' ';
    if (top == -1)
        printf("\nSTACK UNDERFLOW");
    else
        val = st[top--];
    return val;
}

int getPriority(char op) {
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    else
        return -1;
}

void InfixtoPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0') {
        if (source[i] == '(') {
            push(st, source[i]);
            i++;
        } else if (source[i] == ')') {
            while ((top != -1) && (st[top] != '(')) {
                target[j++] = pop(st);
            }
            if (top == -1) {
                printf("\nINCORRECT EXPRESSION");
                
            }
            temp = pop(st); // remove '(' from stack
            i++;
        } else if (isdigit(source[i]) || isalpha(source[i])) {
            target[j++] = source[i++];
        } else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                   source[i] == '/' || source[i] == '%') {
            while ((top != -1) && (st[top] != '(') && 
                    (getPriority(st[top]) >= getPriority(source[i]))) {
                target[j++] = pop(st);
            }
            push(st, source[i]);
            i++;
        } else {
            printf("\nINCORRECT ELEMENT IN EXPRESSION");
            
        }
    }
    while ((top != -1) && (st[top] != '(')) {
        target[j++] = pop(st);
    }
    target[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("\nEnter any infix expression: ");
    gets(infix); // For modern C compilers, use fgets with trimming.
    InfixtoPostfix(infix, postfix);
    printf("\nThe corresponding postfix expression is: %s\n", postfix);
    return 0;
}
