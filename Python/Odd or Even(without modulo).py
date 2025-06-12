#Test 1: Using integer and float division, then comparing both values

def compareIntAndFloat(number):
    if number / 2 == number // 2:
        return "Even"
    else:
        return "Odd"

# Test 2: Dividing number by 2, then multiplying it by 2(number will be same for even numbers, less for odd)

def divideAndMultiply(number):
    if number // 2 * 2 == number:
        return "Even"
    else:
        return "Odd"

# Test 3: Using Bitwise AND to check the LSB(Least Significant Bit) of a number(0 for even numbers, 1 for odd)

def checkLSB(number):
    if number & 1:
        return "Odd"
    else:
        return "Even"

#Test 4: Converting the number to a string and checking the last digit(even number for even numbers, odd number for odd numbers)

def checkLastDigit(number):
    if str(number)[-1] in "02468":
        return "Even"
    else:
        return "Odd"

#Test 5: Recursive function(Repeteaedly calls the function and subtracts 2 from the number until it reaches 0 or 1)

def recursiveFunction(number):
    number = abs(number)
    if number > 1995:
        return "ERROR: Operation cancelled due to reach of max recursion depth. Currently this test cannot handle numbers outside the range of -1995 to 1995.\nFix: Import sys, then use sys.setrecursionlimit(limit)"
    if number == 0:
        return "Even"
    elif number == 1:
        return "Odd"
    else:
        return recursiveFunction(number - 2)


number = int(input("Enter a number: \n"))
print(f"Showing results of all tests for the number {number}\n")

print(f"Test 1: {compareIntAndFloat(number)}")
print(f"Test 2: {divideAndMultiply(number)}")
print(f"Test 3: {checkLSB(number)}")
print(f"Test 4: {checkLastDigit(number)}")
print(f"Test 5: {recursiveFunction(number)}")