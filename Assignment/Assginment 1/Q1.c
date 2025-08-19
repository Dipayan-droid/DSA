#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,x=2,f=0;
    printf("ENter n \n");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int));
    printf("Enter elements: \n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++){
        if (x==arr[i])
        f = 1;
    }
    if (f==1)
    printf("Found");
    else
    printf("Not found");
    return 0;
}