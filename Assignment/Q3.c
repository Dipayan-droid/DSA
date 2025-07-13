#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, min;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    min = arr[0];
    for(i = 1; i < n; i++)
        if(arr[i] < min)
            min = arr[i];
    printf("Minimum element: %d\n", min);
    free(arr);
    return 0;
}
