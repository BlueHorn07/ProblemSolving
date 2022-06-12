import sys

input = sys.stdin.readline().rstrip

N, K = map(int, input().split())

arr = [i for i in range(1, N + 1)]

res = []

idx = 0
while len(arr) > 0:
  idx = (idx + (K-1)) % len(arr)
  res.append(arr[idx])
  del arr[idx]

print('<', end='')
for i in range(len(res) - 1):
  print(res[i], end=', ')
print(f'{res[-1]}>')
