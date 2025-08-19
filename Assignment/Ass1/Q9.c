#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, start, end, i, j;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter start and end index to delete (0-based): ");
    scanf("%d%d", &start, &end);
    if(start < 0 || end >= n || start > end) {
        printf("Invalid range\n");
        free(arr);
        return 0;
    }
    for(i = end + 1, j = start; i < n; i++, j++)
        arr[j] = arr[i];
    n = n - (end - start + 1);
    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
