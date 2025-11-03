#include <stdio.h>
#include <ctype.h>
#define MAX 100

float st[MAX];
int top = -1;

void push(float st[], float val) {
    if(top == MAX - 1) {
        printf("\nSTACK OVERFLOW\n");
    } else {
        top++;
        st[top] = val;
    }
}

float pop(float st[]) {
    float val = -1;
    if(top == -1) {
        printf("\nSTACK UNDERFLOW\n");
    } else {
        val = st[top];
        top--;
    }
    return val;
}

float evaluatePostfixExp(char exp[]) {
    int i = 0;
    float op1, op2, value;
    while(exp[i] != '\0') {
        if(isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0')); // Handle single-digit operands
        } else if(exp[i] == ' ') {
            // Skip spaces for input like "9 3 4 * 8 + 4 / -"
        } else {
            op2 = pop(st);
            op1 = pop(st);
            switch(exp[i]) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '%':
                    value = (int)op1 % (int)op2;
                    break;
                default:
                    printf("\nInvalid operator: %c\n", exp[i]);
                    return 0;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

int main() {
    char exp[100];
    float val;
    printf("\nEnter any postfix expression (single digits, e.g. 9 3 4 * 8 + 4 / -):\n");
    gets(exp); // Or use fgets(exp, sizeof(exp), stdin);
    val = evaluatePostfixExp(exp);
    printf("\nValue of the postfix expression = %.2f\n", val);
    return 0;
}
