import random


if __name__ == "__main__":
    T = 5
    N = 3000
    M = 20000
    print(T)
    for t in range(T):
        K = random.randrange(1, N*M - 1)

        print(N, M, K)
        for i in range(1, N+1):
            print(i, end=' ')
        print()
        for i in range(1, M+1):
            print(i, end=' ')
        print()