#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
} 
void insertatfirst(struct Node **ptr,int data){
    struct Node* newNode = createNode(data);
    newNode->next= *ptr;
    *ptr = newNode;
}
void insertatlast(struct Node **ptr,int data){
    struct Node* newNode = createNode(data);
    if (*ptr==NULL){
        *ptr=newNode;
        return;
    }
    struct Node* temp = *ptr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertatany(struct Node** ptr,int pos, int data){
    struct Node* temp = *ptr;
    for (int i=0;temp!=NULL&& i<pos-1;i++){
        temp=temp->next;
    }
    struct Node * newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(struct Node *ptr){
    while (ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
void delbeg(struct Node** ptr){
    struct Node* temp= *ptr;
    *ptr = (*ptr)->next;
    free(temp);
}
void delatlast(struct Node** ptr){
    if (*ptr==NULL){
        free(*ptr);
        *ptr = NULL;
        return;
    }
    struct Node* temp = *ptr;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void delany(struct Node** ptr,int pos){
    struct Node* temp = *ptr;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
void countNodes(struct Node** head) {
    int count = 0;
    struct Node* temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of Nodes: %d",count) ;
}
int main(){
    struct Node* ptr = NULL;
    int data, ch, pos;
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("4. Display List\n");
        printf("5. Delete at begining\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Any\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("Enter data: ");
            scanf("%d",&data);
            insertatfirst(&ptr,data);
            break;
            case 2:
            printf("Enter data: ");
            scanf("%d",&data);
            insertatlast(&ptr,data);
            break;
            case 3:
            printf("Enter data and pos to enter: ");
            scanf("%d",&data);
            scanf("%d",&pos);
            insertatany(&ptr,pos,data);
            break;
            case 4:
            display(ptr);
            break;
            case 5:
            delbeg(&ptr);
            break;
            case 6:
            delatlast(&ptr);
            break;
            case 7:
            printf("Enter pos to del: ");
            scanf("%d",&pos);
            delany(&ptr,pos);
            break;
            case 8:
            countNodes(&ptr);
            break;
            case 9: 
            exit(0);
            default:
            printf("Wrong Choice");
        }
    }
    return 0;
}
