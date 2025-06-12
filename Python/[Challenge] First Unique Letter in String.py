# Challenge by Zygarde

# Problem: Find the First Non-Repeating Character

# Write a function that takes a string and returns the first character that appears only once.
# If all characters repeat, return an empty string.

# Solve:

text = input()

def first_unique_char(text):

    # Case in-sensitive search
    lower_text = text.lower()

    for char in text:
        # Preserve the letter's case in the output
        if lower_text.count(char.lower()) == 1:
            return char
    return ""

print(first_unique_char(text))