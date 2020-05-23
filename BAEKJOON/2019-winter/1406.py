import sys

word = list(sys.stdin.readline().rstrip())

curser = len(word)

N = int(sys.stdin.readline().rstrip())

for i in range(N):
    print(word, curser)
    command = sys.stdin.readline().rstrip().split()
    if command[0] == 'L':
        if curser != 0:
            curser -= 1
    elif command[0] == 'D':
        if curser != len(word):
            curser += 1
    elif command[0] == 'B':
        if curser != 0:
            del word[curser-1]
            curser -= 1
    elif command[0] == 'P':
        word.insert(curser, command[1])
        curser += 1

print("".join(word))