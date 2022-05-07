import sys
input = sys.stdin.readline

N, M = map(int, input().split())
targets = map(int, input().split())
nums = [i for i in range(1, N+1)]

cost = 0

for target in targets:
  l = len(nums)

  target_pos = -1
  idx = 0
  while idx <= l // 2:
    if nums[idx] == target:
      target_pos = idx
      break
    if nums[l - 1 - idx] == target:
      target_pos = l - 1 - idx
      break
    idx += 1
  
  # move queue to left
  if target_pos <= l // 2:
    cost += target_pos
  else: # move queue to rigth
    cost += (l - target_pos)
  nums = nums[target_pos+1:] + nums[:target_pos]

print(cost)
