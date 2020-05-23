import sys

n, m, k = map(int, input().split())

A_array = list(map(int, input().split()))
B_array = list(map(int, input().split()))

# make matrix C
C_matrix = []

# special case
if k == 1:
    cnt1 = 0
    cnt2 = 0
    for i in range(m):
        if B_array[i] == 1:
            cnt1 += 1
    for i in range(n):
        if A_array[i] == 1:
            cnt2 += 1
    print(cnt1 * cnt2)
    sys.exit()

for i in range(n):
    if A_array[i] == 1:
        C_matrix.append(B_array)
    else:
        C_matrix.append([0 for j in range(m)])


cnt = 0
for r in range(1, k+1):
    if k%r == 0:
        c = k//r
        # search
        for i in range(n): # row
            for j in range(m): # column
                if C_matrix[i][j] == 1:
                    try:
                        if C_matrix[i+r-1][j] == 1 and C_matrix[i][j+c-1] == 1 and C_matrix[i+r-1][j+c-1] == 1:
                            checker = 0
                            break_chk = 0
                            for r_i in range(r):
                                if break_chk == 1:
                                    break
                                for c_j in range(c):
                                    try:
                                        if C_matrix[i+r_i][j+c_j] == 1:
                                            checker += 1
                                        else:
                                            break_chk = 1
                                            break
                                    except:
                                        break_chk = 1
                                        break
                            if break_chk == 0 and checker == k:
                                cnt += 1
                    except:
                        pass
    else: #can't make rectangular
        pass

print(cnt)