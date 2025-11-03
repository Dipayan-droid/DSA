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
void selection_sort(int arr[], int n)
{
    int k, pos, temp;
    for (k = 0; k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}
int main()
{
    int n, pos, found = 0, num;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n], beg = 0, end = n - 1, mid;
    printf("enter the elemets of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n); // Added to sort the array
    printf("\n The sorted array is: \n");
    for (int i = 0; i < n; i++)
        printf(" %d\t", arr[i]);
    printf("\n\n Enter the number that has to be searched: ");
    scanf("%d", &num);
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == num)
        {
            printf("\n %d is present in the array at position %d", num, mid + 1);
            found = 1;
            break;
        }
        else if (arr[mid] > num)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if (beg > end && found == 0)
        printf("\n %d does not exist in the array", num);
    return 0;
}