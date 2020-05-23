word = input()

length = len(word)

fHalf = list(word[:int(length/2)])

if length %2 == 0:
    bHalf = list(reversed(word[int(length/2):]))
    if fHalf == bHalf:
        print(1)
    else:
        print(0)
else:
    bHalf = list(reversed(word[int(length/2)+1:]))
    if fHalf == bHalf:
        print(1)
    else:
        print(0)