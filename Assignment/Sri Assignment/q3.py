k = 1
for i in range(1, 5):
    print(" " * (4 - i), end="")
    for j in range(i):
        print(k, end=" ")
        k += 1
    print()
