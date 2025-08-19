from array import array

arr = array('i', [10, 20, 30, 40, 50])
arr.append(60)
print("After append:", arr.tolist())
