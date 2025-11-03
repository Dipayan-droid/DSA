#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct stack* ptr){
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
void push(struct stack* ptr, int val){
    if(isFull(ptr))
        printf("Stack Overflow! Cant push %d, val\n", val);
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack* ptr){
    if (isEmpty(ptr)) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        return ptr->arr[ptr->top];
    }
}
void display(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements from bottom to top: ");
    for(int i = 0; i <= ptr->top; i++){
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter the size of the stack: ");
    scanf("%d", &sp->size);
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size * sizeof(int));    
    printf("Stack has been created successfully\n");

    int choice, val;
    while(1){
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(sp, val);
                break;
            case 2:
                val = pop(sp);
                if(val != -1) {
                    printf("Popped %d from the stack\n", val);
                }
                break;
            case 3:
                val = peek(sp);
                if(val != -1) {
                    printf("Top element is: %d\n", val);
                }
                break;
            case 4:
                display(sp);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
