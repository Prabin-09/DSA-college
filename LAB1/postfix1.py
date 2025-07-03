postfix = input("Enter the expression")
token = postfix.split()
Stack = []



for char in token:
  if char.isdigit():
    Stack.append(int(char))

  else:

    op1= Stack.pop()
    op2= Stack.pop()

    if char == '+':
      Stack.append(op2 + op1)

    elif char == '-':
      Stack.append(op2 - op1)
 
    elif token == '*':
      Stack.append(op2 * op1)
    
    elif token == '/':
      if (op1 == 0):
       print("Cannot be divided")
      Stack.append(op2 / op1)

    elif token == '^':
      Stack.append(op2 ** op1)

result = Stack.pop()
print (f"the result is {result}")
            






    
    