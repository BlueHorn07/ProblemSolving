seq1 = "ABCDCBA"
seq2 = "DCABBA"
memo = [[0]*len(seq1) for i in range(len(seq2))]


for i in range(len(seq2)):
    for j in range(len(seq1)):
        seq2i = seq2[i]
        seq1j = seq1[j]
        if(i == 0 and j == 0 and seq2i == seq1j):
            memo[i][j] = 1
        elif(i == 0 and j == 0 and seq2i != seq1j):
            memo[i][j] = 0
        elif(i == 0 and j > 0 and seq2i == seq1j):
            memo[i][j] = memo[i][j-1] + 1
        elif(i == 0 and j > 0 and seq2i != seq1j):
            memo[i][j] = memo[i][j-1]
        elif(i > 0 and j == 0 and seq2i == seq1j):
            memo[i][j] = memo[i-1][j] + 1
        elif(i > 0 and j == 0 and seq2i != seq1j):
            memo[i][j] = memo[i-1][j]
        elif(i > 0 and j > 0 and seq2i == seq1j):
            memo[i][j] = max(memo[i-1][j], memo[i][j-1]) + 1
        elif(i > 0 and j > 0 and seq2i != seq1j):
            memo[i][j] = max(memo[i-1][j], memo[i][j-1])
        else:
            print(seq2[i], seq1[j])

for row in memo:
    print(row)