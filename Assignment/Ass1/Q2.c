#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, i, j, temp;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter position : ");
    scanf("%d", &pos);
    for(i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if(arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    
    printf("%dth max element: %d\n", pos, arr[pos-1]); 
    free(arr);
    return 0;
}
