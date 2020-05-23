import sys

if __name__ == "__main__":
    N = int(input())
    stack = [0]
    result = []
    prev = 0
    cnt = 1
    isNO = False
    for _ in range(N):
        num = int(input())
        if not isNO:
            if(stack[-1] < num):
                for i in range(cnt, num+1):
                    stack.append(i)
                    result.append("+")
                    cnt += 1
                stack.pop()
                result.append("-")

            else:
                if(num == stack[-1]):
                    result.append("-")
                    stack.pop()
                else:
                    isNO = True
            prev = num
    if isNO == True:
        print("NO")
    else:
        for w in result:
            print(w)