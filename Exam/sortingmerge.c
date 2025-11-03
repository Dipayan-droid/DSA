#include <stdio.h>
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg, temp[100], k;
    while(i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i > mid)
    {
        while(j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k = beg; k < index; k++)
        arr[k] = temp[k];
}
void mergesort(int arr[], int beg, int end)
{
    int mid;
    if(beg < end)
    {
        mid = (beg + end) / 2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main(){
    int n, pos, found = 0, temp, i, j, k;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elemets of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
        printf("\n The sorted array is: \n");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}