N = int(input())
 
robo = list(map(int, input().split()))
 
bio = list(map(int, input().split()))
 
points = [0 for i in range(N)]
 
r_cnt = 0
b_cnt = 0
 
for i in range(N):
    if robo[i] == 0 and bio[i] == 1:
        b_cnt += 1
    elif robo[i] == 1 and bio[i] == 0:
        r_cnt += 1
    
if r_cnt == b_cnt + 1 or r_cnt > b_cnt:
    print(1)
elif r_cnt == 0 or b_cnt == 0:
    print(-1)
else:
    if (b_cnt + 1)%r_cnt == 0:
        print(int((b_cnt + 1)/r_cnt))
    else:
        print(int((b_cnt + 1)/r_cnt)+1)