#include <stdio.h>
#include <stdlib.h>
int main(){
    int *arr;
    int n,i,key,found=0;
    printf("Enter number of eleemets: ");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter elemets: ");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
    }
    if (found==0)
    printf("Not Found");

    return 0;
}