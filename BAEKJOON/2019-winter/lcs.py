import sys

T = int(input())

for t in range(T):
    M, D = map(int, input().split())

    D = D - M
    M = 0

    if D <= 1:
        print(D)
        continue

    Sum = 0
    i = 1
    while True:
        Sum += i

        if Sum * 2 == (D-1):
            print(i*2 + 1)
            break
        elif Sum * 2 < (D-1):
            if Sum * 2 + (i+1) == (D-1):
                print(i*2 + 1 + 1)
                break
            elif Sum * 2 + (i+1) > (D-1):
                print(i*2 + 1)
                break
        else:
            print(i*2 - 1 + 1)
            break

        i += 1

