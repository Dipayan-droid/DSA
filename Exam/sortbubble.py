def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))

bubble_sort(arr)
print("Sorted array:", arr)
