#include <stdio.h>
#include<stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int* arr;
};
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;}
    else return 0;
}
int isFull(struct queue *q){
    if(q->r==q->size-1)
    return 1;
    else
    return 0;
}
void enqueue(struct queue *q,int val){
    if (isFull(q))
    printf("Full");
    else{
        q->r++;
        q->arr[q->r]=val;
    }
}
void display(struct queue *q){
    if (isEmpty(q))
    printf("Empty");
    else{
        for(int i=q->f+1;i<=q->r;i++){
            printf("%d ", q->arr[i]);
        }
    } 
}
int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Empty");
        return -1;}
    else{
        q->f++;
        return q->arr[q->f];
    }
}

int main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));
     // Call all functions:
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);

    display(&q);

    int val = dequeue(&q);
    if (val != -1)
        printf("Dequeued: %d\n", val);

    display(&q);

    enqueue(&q, 20);
    display(&q);

    return 0;
}