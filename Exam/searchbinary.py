def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))
num = int(input("Enter number to search: "))

arr.sort()  # ensure sorted array for binary search

pos = binary_search(arr, num)
if pos == -1:
    print(f"{num} not found in array")
else:
    print(f"{num} found at position {pos + 1}")
