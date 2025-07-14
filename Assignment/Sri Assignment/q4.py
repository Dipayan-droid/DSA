a, b = 0, 1
n = int(input("Enter range: "))
print(a, b, end=", ")
for i in range(2, n):
    c = a + b
    print(c, end=", " if i < 9 else "")
    a = b
    b = c
