def reverse_string_stack(s):
    stack = []
    for char in s:
        stack.append(char)
    reversed_str = ''
    while stack:
        reversed_str += stack.pop()
    return reversed_str

# Example usage
text = input("Enter a string to reverse: ")
print("Reversed string:", reverse_string_stack(text))
