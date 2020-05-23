import sys

if __name__ == "__main__":
    num = list(sys.stdin.readline().rstrip())
    num.sort(reverse = True)
    print(''.join(num))
