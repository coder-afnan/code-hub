# Challenge by Zygarde

# Problem: Find the Factorial

# Write a function that takes a non-negative integer as input and returns its factorial.
# The factorial of a number n (n!) is the product of all positive integers from 1 to n.
# Do not use built-in factorial() function.
#
# Input:
# - A single non-negative integer num (0 ≤ num ≤ 10).
#
# Output:
# - An integer representing the factorial of num.
#
# Example Runs:
#
# Example 1:
# Input: 5
# Output: 120
# (Explanation: 5! = 5 × 4 × 3 × 2 × 1 = 120)
#
# Example 2:
# Input: 0
# Output: 1
# (Explanation: By definition, 0! = 1)
#
# Example 3:
# Input: 3
# Output: 6
# (Explanation: 3! = 3 × 2 × 1 = 6)


def factorial(num):
    # Write your code here👍
    result = 1
    for n in range(1, num + 1):
        result *= n
    return result


















































# Example
print(factorial(int(input())))

# Assertions to test the function
assert factorial(5) == 120
assert factorial(0) == 1
assert factorial(3) == 6
assert factorial(1) == 1
assert factorial(7) == 5040

print("All test cases passed!")