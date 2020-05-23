import sys

N, K = map(int, sys.stdin.readline().rstrip().split())

idx = 1

nums = [i for i in range(1, N+1)]
print("<", end='')
while N > 0:
    idx = (idx + (K-1))%N
    if idx == 0:
        idx = N
    if N >= 2:
        print(nums[idx-1], end=', ')
        del nums[idx-1]
    N -= 1
print(str(nums[0])+">")