inputs = []

for i in range(9):
    inputs.append(int(input()))

inputs.sort()

sorted_sum = 0

for i in range(7):
    sorted_sum += inputs[i]

diff_8th = [0 for i in range(7)]
diff_9th = [0 for i in range(7)]

for i in range(7):
    diff_8th[i] = inputs[7] - inputs[i]
    diff_9th[i] = inputs[8] - inputs[i]

answer = inputs[0:7]

for i in range(7):
    if sorted_sum != 100:
        if sorted_sum + diff_8th[i] == 100:
            answer[i] = inputs[7]
            break
        if sorted_sum + diff_9th[i] == 100:
            answer[i] = inputs[8]
            break

        for j in range(7):
            if i!= j:
                if sorted_sum + diff_8th[i] + diff_9th[j] == 100:
                    answer[i] = inputs[7]
                    answer[j] = inputs[8]
                    sorted_sum = 100
                    break
                    
answer.sort()

for i in range(7):
    print(answer[i])
