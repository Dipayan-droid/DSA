def validate_parenthesis(expr):
    stack = []
    pairs = {')': '(', '}': '{', ']': '['}
    for char in expr:
        if char in '([{':
            stack.append(char)
        elif char in ')]}':
            if not stack or stack.pop() != pairs[char]:
                return False
    return not stack

# Example usage
expression = input("Enter an expression to validate: ")
if validate_parenthesis(expression):
    print("Valid Expression")
else:
    print("Invalid Expression")
