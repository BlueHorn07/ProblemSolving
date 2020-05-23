
import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    nums = []
    for i in range(N):
        nums.append(int(sys.stdin.readline().rstrip()))
        

    nums.sort(reverse = True)
    for n in nums:
        print(n)

