# Challenge by Zygarde

# Problem: Longest Word in a Sentence

# Write a function that takes a sentence (string) and returns the longest word.
# If multiple words have the same maximum length, return the first one.
#
# Input:
# - A string containing words separated by spaces (length ≤ 100).
#
# Output:
# - A string representing the longest word.
#
# Example Runs:
#
# Example 1:
# Input: "The quick brown fox"
# Output: "quick"
# (Explanation: 'quick' and 'brown' are the longest, but 'quick' appears first)
#
# Example 2:
# Input: "Python is amazing"
# Output: "amazing"
# (Explanation: 'amazing' is the longest word)
#
# Example 3:
# Input: "I love AI"
# Output: "love"
# (Explanation: 'love' is the longest word)

def longest_word(sentence):
    # Write your code here👍
    words = sentence.split()
    return max(words, key = len)































# Example
print(longest_word(input()))

# Assertions to test the function
assert longest_word("The quick brown fox") == "quick"
assert longest_word("Python is amazing") == "amazing"
assert longest_word("I love AI") == "love"
assert longest_word("123 1234 12") == "1234"
assert longest_word("Programming") == "Programming"

print("All test cases passed!")