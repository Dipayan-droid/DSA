#include <stdio.h>
int smallest(int arr[], int k, int n)
{
    int pos = k, small = arr[k], i;
    for (i = k + 1; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int n, pos, found = 0, temp, i, j, k;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elemets of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (k = 0; k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;}
    printf("\n The sorted array is: \n");
    for (i = 0; i < n; i++)
        printf(" %d ", arr[i]);
    
    return 0;
}