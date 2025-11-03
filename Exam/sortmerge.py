def merge(arr, left, mid, right):
    left_sub = arr[left:mid+1]
    right_sub = arr[mid+1:right+1]
    i = j = 0
    k = left
    
    while i < len(left_sub) and j < len(right_sub):
        if left_sub[i] < right_sub[j]:
            arr[k] = left_sub[i]
            i += 1
        else:
            arr[k] = right_sub[j]
            j += 1
        k += 1
    
    while i < len(left_sub):
        arr[k] = left_sub[i]
        i += 1
        k += 1
    while j < len(right_sub):
        arr[k] = right_sub[j]
        j += 1
        k += 1

def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)
        merge(arr, left, mid, right)

n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))

merge_sort(arr, 0, n - 1)
print("Sorted array:", arr)
