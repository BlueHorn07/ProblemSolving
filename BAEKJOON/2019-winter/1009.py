N = int(input())

for i in range(N):
    a, b = map(int, input().split())
    a = a % 10
    b = b % 4
    if b == 0:
        b = 4
    answer = (a**b)%10
    if answer == 0:
        print(10)
    else:
        print(answer)
    