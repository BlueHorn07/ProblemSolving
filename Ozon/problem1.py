T = int(input())

for t in range(T):
    N = int(input())

    necklace = list(map(int, input().split()))
    bracelet = list(map(int, input().split()))
    necklace.sort()
    bracelet.sort()
    for i in range(N):
        print(necklace[i], end=' ')
    print()
    for i in range(N):
        print(bracelet[i], end=' ')
    print()

