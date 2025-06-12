num1 = int(input("Enter the first number: "))
operator = input("Enter the operator sign(+, -, *, /): ")
num2 = int(input("Enter the second number: "))
result = 0

match operator:
    case "+":
        result = num1 + num2
    case "-":
        result = num1 - num2
    case "*":
        result = num1 * num2
    case "/":
        result = num1 / num2
    default:
        print("Invalid operator. Please enter one of these: +, -, *, /")

print(f("The result of the expression is {result}"))