n = int(input("Enter range "))
for num in range(1, n+1):
    temp = num
    sum = 0
    while temp > 0:
        rem = temp % 10
        sum += rem ** 3
        temp //= 10
    if sum == num:
        print(num, end=" ")
