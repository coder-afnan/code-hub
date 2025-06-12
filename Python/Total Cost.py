items = int(input("Enter the number of items"))
cost_per_item = float(input("Enter the cost per item"))
tax = float(input("Enter the tax amount in percentage, without % sign"))
tax /= 100

initial_cost = items * cost_per_item
total_cost = initial_cost + (initial_cost * tax)

print(f("The total cost for the items without tax is ${initial_cost}, and with tax, it is ${total_cost}"))