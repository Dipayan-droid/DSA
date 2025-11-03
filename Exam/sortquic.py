def partition(arr, low, high):
    pivot = arr[low]
    left = low + 1
    right = high
    
    done = False
    while not done:
        while left <= right and arr[left] <= pivot:
            left = left + 1
        while arr[right] >= pivot and right >= left:
            right = right - 1
        if right < left:
            done = True
        else:
            arr[left], arr[right] = arr[right], arr[left]
    arr[low], arr[right] = arr[right], arr[low]
    return right

def quick_sort(arr, low, high):
    if low < high:
        split_point = partition(arr, low, high)
        quick_sort(arr, low, split_point - 1)
        quick_sort(arr, split_point + 1, high)

n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))

quick_sort(arr, 0, n - 1)
print("Sorted array:", arr)
