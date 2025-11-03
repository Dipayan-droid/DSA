#include <stdio.h>

int main(){
    int n,pos,found=0,temp,i,j;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elemets of the array: ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
        for(i=1; i<n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while((temp < arr[j]) && (j >= 0))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("\n The sorted array is: \n");
    for(i=0; i<n; i++)
        printf(" %d  ", arr[i]);
    return 0;
}