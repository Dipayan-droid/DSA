n = 5  
for i in range(n):
    print(" " * (n - i - 1), end="")
    for j in range(2 * i + 1):
        print(n - abs(i - j), end="")
    print()
for i in range(n - 2, -1, -1):
    print(" " * (n - i - 1), end="")
    for j in range(2 * i + 1):
        print(n - abs(i - j), end="")
    print()
