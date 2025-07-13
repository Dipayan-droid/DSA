#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i, j, temp;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int *a = (int*)malloc(n1 * sizeof(int));
    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int *b = (int*)malloc(n2 * sizeof(int));
    printf("Enter elements of second array:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &b[i]);
    int *c = (int*)malloc((n1 + n2) * sizeof(int));
    for(i = 0; i < n1; i++)
        c[i] = a[i];
    for(i = 0; i < n2; i++)
        c[n1 + i] = b[i];
    for(i = 0; i < n1 + n2 - 1; i++)
        for(j = 0; j < n1 + n2 - i - 1; j++)
            if(c[j] > c[j+1]) {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
    printf("Merged sorted array:\n");
    for(i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);
    printf("\n");
    free(a); free(b); free(c);
    return 0;
}
