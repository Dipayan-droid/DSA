#include <stdio.h>
#include <stdlib.h>
struct stud
{
    int data;
    struct stud *next;
};
typedef struct stud node;
node *head = NULL;
void create(node *ptr)
{
    int n;
    node *newnode;
    printf("Enter no");
    scanf("%d", &n);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if (ptr == NULL)
    {
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}
void display(node *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty list");
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d-->", ptr->data);
            ptr = ptr->next;
        }
    }
}
void insertbeg()
{
    node *newnode;
    int n;
    printf("Enter value to insert at the beginning");
    scanf("%d", &n);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;
}
void insertmid(node *ptr)
{
    node *newnode;
    int n, k = 1, loc;
    printf("Enter value to insert at the middle");
    scanf("%d", &n);
    printf("Enter the position number AT which you will insert");
    scanf("%d", &loc);

    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;

    while (ptr->next != NULL)
    {
        if (k + 1 == loc)
            break;
        ptr = ptr->next;
        k = k + 1;
    }

    if (ptr->next == NULL)
    {
        printf("invalid no");
        return;
    }

    else
    {
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}
void del_beg()
{
    node *temp;
    temp = head;
    head = head->next;
    free(temp);
}
void del_mid()
{
    int n;
    node *ptr = head;
    node *prev = head;
    printf("Which data number do you want to delete?");
    scanf("%d", &n);
    while (ptr != NULL)
    {
        if (ptr->data == n)
            break;
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }

    if (ptr == NULL)
    {
        printf("invalid no");
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}
void del_last(node *ptr)
{
    node *prev = head;
    if (head == NULL)
    {
        printf("empty");
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {

            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("invalid no");
            return;
        }
        prev->next = NULL;
        free(ptr);
    }
}
void main()
{
    int ch;
    while (1)
    {
        printf("\n Enter ur choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            insertbeg();
            break;
        case 4:
            insertmid(head);
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_mid();
            break;
        case 7:
            del_last(head);
            break;
        case 8:
            exit(0);
        }
    }
}
