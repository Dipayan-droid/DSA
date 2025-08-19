#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i, j, k;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int *a = (int*)malloc(n1 * sizeof(int));
    printf("Enter sorted elements of first array:\n");
    for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int *b = (int*)malloc(n2 * sizeof(int));
    printf("Enter sorted elements of second array:\n");
    for(i = 0; i < n2; i++)
        scanf("%d", &b[i]);
    int *c = (int*)malloc((n1 + n2) * sizeof(int));
    i = j = k = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i < n1)
        c[k++] = a[i++];
    while(j < n2)
        c[k++] = b[j++];
    printf("Merged array:\n");
    for(i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);
    printf("\n");
    free(a); free(b); free(c);
    return 0;
}
