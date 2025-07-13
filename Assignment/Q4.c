#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c, i, j, key, found = 0;
    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);
    int **arr = (int**)malloc(r * sizeof(int*));
    for(i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));
    printf("Enter elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            if(arr[i][j] == key) {
                found = 1;
                break;
            }
    if(found)
        printf("Element found\n");
    else
        printf("Element not found\n");
    
    return 0;
}
