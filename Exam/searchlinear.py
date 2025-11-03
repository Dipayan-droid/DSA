def linear_search(arr, target):
    for i, val in enumerate(arr):
        if val == target:
            return i
    return -1

n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))
num = int(input("Enter number to search: "))

pos = linear_search(arr, num)
if pos == -1:
    print(f"{num} not found in array")
else:
    print(f"{num} found at position {pos + 1}")
