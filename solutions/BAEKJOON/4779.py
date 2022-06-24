import sys
input = sys.stdin.readline

def cantor(n, ret):
  if n <= 1: return ret

  step = n // 3
  tmp = 0
  flag = False

  for i in range(len(ret)):
    if flag:
      tmp -= 1
      ret[i] = " "
    else:
      tmp += 1

    if tmp == step:
      flag = True
    if tmp == 0:
      flag = False
  
  return cantor(step, ret)

try:
  while True:
    N = int(input())
    final_ret = cantor(3**N, ["-" for _ in range(3**N)])
    print(''.join(final_ret))
except:
  exit()