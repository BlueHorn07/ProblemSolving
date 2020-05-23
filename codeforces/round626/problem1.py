T = int(input())

for i in range(T):
    length = int(input())
    nums = list(map(int, input().split()))
    temp = -1
    check = 0
    for j in range(length):
        if nums[j]%2 == 0:
            print(1)
            print(j+1)
            check = 1
            break
        else:
            if temp == -1:
                temp = j
            else:
                print(2)
                print(temp+1, j+1)
                check = 1
                break
    if check == 0:
        print(-1)  


