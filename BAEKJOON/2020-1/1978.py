import sys

MAX = 123456 * 2 + 1

prime_checker = [True] * (MAX+2)
prime_checker[0] = False
prime_checker[1] = False

if __name__ == "__main__":
    for i in range(2, int(MAX**0.5)+1):
        if(prime_checker[i]):
            for j in range(int(i*i), MAX+1, i):
                prime_checker[j] = False
    while(True):
        N = int(sys.stdin.readline().rstrip())

        if(N == 0):
            break
        cnt = 0
        for i in range(N+1, 2*N+1):
            if(prime_checker[i]):
                cnt += 1
        print(cnt)
