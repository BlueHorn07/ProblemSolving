import sys
N = int(input())

seq = []

for n in range(N):
    seq.append(int(input()))


stack = []

idx = 0
last = 0

result = []

while idx < N:
    try:
        for i in range(last+1, seq[idx]+1):
            result.append('+')
            stack.append(i)
        last = seq[idx]
        while stack[-1] == seq[idx]:
            result.append('-')
            stack.pop()
            idx += 1
            if idx >= N:
                break
    except:
        print("NO")
        sys.exit()
        break
    if stack:
        if seq[idx] < stack[-1]:
            print("NO")
            sys.exit()
            break

for i in range(len(result)):
    print(result[i])