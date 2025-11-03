#include <stdio.h>

int main(){
    int n,pos,found=0,num;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elemets of the array: ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the elemet to search:");
    scanf("%d",&num);
    for (int i=0;i<n;i++){
        if (arr[i]==num){
            found = 1;
            pos = i;
            printf("%d is found in pos: %d",num,pos);
        }
    }
    if (found==0){
        printf("Item not found");
    }
    return 0;
}