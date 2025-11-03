import array

# Create array of 5 integers
arr = array.array('i', [10, 20, 30, 40, 50])

# Display all items
print("Array items:", arr)

# Access individual elements through indexes
for i in range(len(arr)):
    print(f"Element at index {i}: {arr[i]}")
import array

arr = array.array('i', [10, 20, 30])
print("Original array:", arr)

# Append new item
arr.append(40)
print("Array after appending 40:", arr)
import array

arr = array.array('i', [1, 2, 3, 4, 5])
print("Original array:", arr)

# Reverse the array
arr.reverse()
print("Reversed array:", arr)
import array

arr = array.array('i', [1, 2, 2, 3, 4, 2, 5])
print("Array:", arr)

element = 2
count = arr.count(element)
print(f"Number of occurrences of {element}:", count)
import array

arr = array.array('i', [10, 20, 30, 40, 50, 60])
print("Array members:")
for item in arr:
    print(item)
