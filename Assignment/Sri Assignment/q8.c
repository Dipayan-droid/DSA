#include <stdio.h>
int main() {
    int arr[5], n = 5, i, val, pos = -1;
    printf("Enter 5 elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter value to delete: ");
    scanf("%d", &val);
    for(i = 0; i < n; i++) {
        if(arr[i] == val) {
            pos = i;
            break;
        }
    }
    if(pos != -1) {
        for(i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
        printf("Array after deletion: ");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
    } else {
        printf("Value not found");
    }
    return 0;
}
