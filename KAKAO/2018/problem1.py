import sys

reward2017 = [(1, 500), (2, 300), (3, 200), (4, 50), (5, 30), (6, 10)]
reward2018 = [(1, 512), (2, 256), (4, 128), (8, 64), (16, 32)]

if __name__ == "__main__":
    T = int(input())
    for t in range(T):
        a, b = map(int, input().split())
        sum = 0
        cnt_a = 0
        cnt_b = 0
        if a != 0:
            for num, reward in reward2017:
                cnt_a += num
                if a <= cnt_a:
                    sum += reward
                    break
        if b != 0:
            for num, reward in reward2018:
                cnt_b += num
                if b <= cnt_b:
                    sum += reward
                    break

        print(sum * 10000)