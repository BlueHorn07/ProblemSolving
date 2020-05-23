import sys

NUM = 1000000
P = 15*(10**5)
sys.setrecursionlimit(P+1)

cnt = 0
def fibo(n):
    global cnt
    cnt = cnt + 1
    if n<=1:
        memo[n] = n
        return n
    if memo[n] != -1:
        return memo[n]
    else:
        memo[n] = (fibo(n-1)%NUM + fibo(n-2)%NUM)%NUM
        return memo[n]


N = int(input())

print(N%P)

memo = [-1 for i in range(N%P+1)]

print(fibo(N%P))
print(cnt)

