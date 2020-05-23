def OpPriority(op):
    if(op == '*' or op == '/'):
        return 5
    elif(op == '+' or op == '-'):
        return 3
    else:
        return 0

def isOperator(c):
    if(c == '+' or c == '-' or c == '*' or c == '/'):
        return True
    else:
        return False

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        midfix = list(input())

        # start & end character check
        if(midfix[0] == '-' or midfix[0] == '+'):
            midfix.insert(0, '0')
        
        WrongBit = False
        if(isOperator(midfix[0]) or isOperator(midfix[-1])):
            print("WRONG INPUT")
            WrongBit = True
            continue
        
        for i in range(len(midfix)-1):
            if(isOperator(midfix[i]) and isOperator(midfix[i+1])):
                print("WRONG INPUT")
                WrongBit = True
                break
            elif((not isOperator(midfix[i])) and (not isOperator(midfix[i+1]))):
                print("WRONG INPUT")
                WrongBit = True
                break
        
        if(WrongBit):
            continue

        postfix = []
        stack = []
        for c in midfix:
            # if it is number just push
            if(not isOperator(c)):
                postfix.append(c)
                continue
            else:
                # it is operator
                if(not stack): # if empty stack
                    stack.append(c)
                    continue
                else:
                    if(OpPriority(stack[-1]) < OpPriority(c)):
                        stack.append(c)
                        continue
                    else:
                        postfix.append(stack[-1])
                        stack.pop()
                        stack.append(c)
                        continue
        while(stack):
            postfix.append(stack[-1])
            stack.pop()
        print(postfix)
        
        # calculate the result        
        for c in postfix:
            print(stack)
            if(not isOperator(c)):
                stack.append(int(c))
                continue
            else:
                op2 = stack[-1]
                stack.pop()
                op1 = stack[-1]
                stack.pop()
                if(c == '+'):
                    stack.append(op1 + op2)
                    continue
                elif(c == '-'):
                    stack.append(op1 - op2)
                    continue
                elif(c == '*'):
                    stack.append(int(op1 * op2))
                    continue
                elif(c == '/'):
                    if(op2 == 0): # divide by zero
                        print("WRONG INPUT")
                        WrongBit = True
                        break
                    stack.append(int(op1 / op2))
                    continue
                
        
        if(WrongBit):
            continue  
        print(stack[-1])
    
