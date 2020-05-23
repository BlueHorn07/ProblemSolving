import copy

N = int(input())

result = []

for i in range(N):
    nums = list(map(int, input().split()))
    if i == 0:
        result = copy.deepcopy(nums)
    else:
        temp = []
        for j in range(i+1):
            if j == 0:
                temp.append(result[0] + nums[0])
            elif j == i:
                temp.append(result[-1] + nums[-1])
            else:
                temp.append(nums[j] + max(result[j-1], result[j]))

        result = copy.deepcopy(temp)


print(max(result))

            

