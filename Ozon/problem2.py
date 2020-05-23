word = list(input())

result = []

while True:
    i = 0
    j = len(word) - 1

    del_list = []

    check = 0

    while i <= j:
        #print(i, j, check,  "test")
        if check == 0: # front tracking
            if word[i] != '(':
                i += 1
            else:
                del_list.append(i+1)
                check = 1
                i += 1
        else: # back tracking
            if word[j] != ')':
                j -= 1
            else:
                del_list.append(j+1)
                check = 0
                j -= 1

    if len(del_list) % 2 != 0:
        del_list.pop()
    
    del_list.sort()


    cnt = 0
    for e in del_list:
        #print(del_list, cnt, e, len(word))
        del word[e - 1 - cnt]
        cnt += 1

    if not del_list :
        break


    result.append(del_list)

print(len(result))
for i in range(len(result)):
    print(len(result[i]))
    for j in range(len(result[i])):
        print(result[i][j], end=' ')
    print()
