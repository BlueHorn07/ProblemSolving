# *, / -- 1순위
# +, - -- 2순위


import sys
T = int(input())

for t in range(T):
    word = list(input())
    chk = 0
    i = 0

    if word[0] == '-':
        if i+1 < len(word):
            word[i] = (-1)*int(word[i+1])
            del word[i+1]
    elif word[0] == '-':
        if i+1 < len(word):
            word[i] = int(word[i+1])
            del word[i+1]

    while i < len(word):
        if word[i] == '*' or word[i] == '/' or word[i] == '+' or word[i] == '-': 
            if i+1 < len(word):
                if word[i+1] == '*' or word[i+1] == '/':
                    print("WRONG INPUT")
                    chk = -1
                    break
                elif word[i+1] == '+' or word[i+1] == '-':
                    if i+2 < len(word):
                        if word[i+1] == '-':
                            if 48 <= ord(word[i+2]) and ord(word[i+2]) <= 57:
                                word[i+1] = (-1)*int(word[i+2])
                                del word[i+2]
                            else:
                                print("WRONG INPUT")
                                chk = -1
                                break
                        elif word[i+1] == '+':
                                if 48 <= ord(word[i+2]) and ord(word[i+2]) <= 57:
                                    word[i+1] = int(word[i+2])
                                    del word[i+2]
                                else:
                                    print("WRONG INPUT")
                                    chk = -1
                                    break
                    else:
                        print("WRONG INPUT")
                        chk = -1
                        break
            else:
                print("WRONG INPUT")
                chk = -1
                break
                
        i += 1

    # WRONG INPUT
    if chk == -1:
        continue

    stack = []
    postfix = []

    for i in range(len(word)):
        
        if word[i] == '*' or word[i] == '/':
            stack.append(word[i])
            
        elif word[i] == '+' or word[i] == '-':
            if stack:
                if stack[-1] != '*' or stack[-1] != '/':
                    postfix.append(stack[-1])
                    stack.pop()
                    stack.append(word[i])
            else:
                stack.append(word[i])
        else: # just number
            postfix.append(word[i])
            

    
    while stack:
        postfix.append(stack[-1])
        stack.pop()

    # Calculation
    #print(postfix)
    postfix = postfix[::-1]
    stack = []
    result = 0
    while postfix:
        #print(postfix, stack)
        if postfix[-1] == '+' or postfix[-1] == '-' or postfix[-1] == '*' or postfix[-1] == '/':
            if stack:
                n1 = stack[-1]
                stack.pop()
            else:
                print("WRONG INPUT")
                chk = -1
                break
            if stack:
                n2 = stack[-1]
                stack.pop()
            else:
                print("WRONG INPUT")
                chk = -1
                break

            if postfix[-1] == '+':
                stack.append(n2 + n1)
            elif postfix[-1] == '-':
                stack.append(n2 - n1)
            elif postfix[-1] == '*':
                stack.append(n2 * n1)
            elif postfix[-1] == '/':
                if n1 == 0:
                    print("WRONG INPUT") # Divided by 0
                    chk = -1
                    break
                #print(n2, n1)
                stack.append(int(n2 / n1))
        else:
            stack.append(int(postfix[-1]))
        postfix.pop()

    # WRONG INPUT
    if chk == -1:
        continue
    
    print(stack[0])
