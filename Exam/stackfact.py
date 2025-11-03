def factorial_stack(n):
    stack = []
    result = 1
    while n > 1:
        stack.append(n)
        n -= 1
    while stack:
        result *= stack.pop()
    return result

# Example usage
num = int(input("Enter a number for factorial: "))
print("Factorial:", factorial_stack(num))
