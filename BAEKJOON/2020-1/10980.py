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

        mod_midfix = []
        for i in range(0, len(midfix)-2, 2):
            #print(i, mod_midfix)
            if(midfix[i+1] == '+' or midfix[i+1] == '-'):
                if(not mod_midfix):
                    mod_midfix.append(midfix[i])
                elif(isOperator(mod_midfix[-1])):
                    mod_midfix.append(midfix[i])

                mod_midfix.append(midfix[i+1])
            else:
                if(midfix[i+1] == '*'):
                    if(not mod_midfix):
                        mod_midfix.append(int(midfix[i]) * int(midfix[i+2]))
                    elif(isOperator(mod_midfix[-1])):
                        mod_midfix.append(int(midfix[i]) * int(midfix[i+2]))
                    else:
                        mod_midfix[-1] = (int(mod_midfix[-1]) * int(midfix[i+2]))
                else:
                    if(int(midfix[i+2]) == 0):
                        print("WRONG INPUT")
                        WrongBit = True
                        break
                    if(not mod_midfix):
                        mod_midfix.append(int(midfix[i]) // int(midfix[i+2]))
                    elif(isOperator(mod_midfix[-1])):
                        mod_midfix.append(int(midfix[i]) // int(midfix[i+2]))
                    else:
                        mod_midfix[-1] = (int(mod_midfix[-1]) // int(midfix[i+2]))
        
        if(WrongBit):
            continue

        if(not mod_midfix):
            mod_midfix.append(midfix[0])
        elif(isOperator(mod_midfix[-1])):
            mod_midfix.append(midfix[-1])


        result = int(mod_midfix[0])
        for i in range(0, len(mod_midfix)-2, 2):
            if(mod_midfix[i+1] == '+'):
                result += int(mod_midfix[i+2])
            else:
                result -= int(mod_midfix[i+2])

        print(result)






    
