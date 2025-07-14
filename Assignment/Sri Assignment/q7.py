from array import array

input_str = input("Enter 5 elements: ")
elements = input_str.split()
arr = array('i', [int(x) for x in elements])

maxi = mini = arr[0]
for x in arr[1:]:
    if x > maxi:
        maxi = x
    if x < mini:
        mini = x
print("Max:", maxi)
print("Min:", mini)
