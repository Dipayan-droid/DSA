#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, new_n;
    printf("Enter initial size: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter new size: ");
    scanf("%d", &new_n);
    arr = (int*)realloc(arr, new_n * sizeof(int));
    if(new_n > n) {
        printf("Enter new elements:\n");
        for(i = n; i < new_n; i++)
            scanf("%d", &arr[i]);
    }
    printf("Array after resizing:\n");
    for(i = 0; i < new_n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
