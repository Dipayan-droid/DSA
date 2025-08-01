#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size ;
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
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

void push(struct stack* ptr, int val){
    if(isFull(ptr))
    printf("Stack Overflow! Cant push %d, val");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
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
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int stackBottom(struct stack* sp){
    return sp->arr[0];
}

int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size*sizeof(int));    
    printf("Stack has been created successfully \n ");
    printf("%d\n",isEmpty(sp));
    printf("%d\n",isFull(sp));
    push(sp,45);
    push(sp,1);
    push(sp,4);
    push(sp,68);
    push(sp,12);
    push(sp,85);
    push(sp,11);
    push(sp,63);

    printf("Popped %d from the stack\n", pop(sp));
    printf("%d\n",isEmpty(sp));
    printf("%d\n",isFull(sp));
        // Printing values from the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    printf("The top most value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));
    
    return 0;
}
 