import sys

N = int(input())

word = input()

# size odd/even check
if N % 2 != 0:
    print(-1)
    sys.exit()

# each number check
l_cnt = 0
r_cnt = 0
for i in range(N):
    if word[i] == '(':
        l_cnt += 1
    else:
        r_cnt += 1

if l_cnt != r_cnt:
    print(-1)
    sys.exit()

result = 0
checker = 0
l_cnt = 0
r_cnt = 0
for i in range(N):
    if checker == 0:
        checker = word[i]
        if checker == '(':
            l_cnt += 1
        else:
            r_cnt += 1
    else:
        if word[i] == ')':
            r_cnt += 1
        else:
            l_cnt += 1

        if r_cnt == l_cnt:
            if checker == '(':
                pass
            else:
                if word[i] == '(':
                    result += l_cnt + r_cnt
            r_cnt = 0
            l_cnt = 0
            checker = 0
        
print(result)