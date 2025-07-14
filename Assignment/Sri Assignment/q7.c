#include <stdio.h>
int main() {
    int arr[5], i, max, min;
    printf("Enter 5 elements: ");
    for(i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    max = min = arr[0];
    for(i = 1; i < 5; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    printf("Max: %d\nMin: %d\n", max, min);
    return 0;
}
