inputs = list(map(int, input().split()))

all_sum = max(inputs)

for i in range(4):
    if inputs[i] != all_sum:
        print(all_sum - inputs[i], end=" ")


