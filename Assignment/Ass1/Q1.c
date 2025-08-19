#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, key, found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            break;
        }
    }
    if(found)
        printf("Element found at index %d\n", i);
    else
        printf("Element not found\n");
    free(arr);
    return 0;
}
