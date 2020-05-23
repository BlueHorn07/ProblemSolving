import sys
from collections import defaultdict 

if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().rstrip().split())
    name_num = defaultdict(int)
    num_name = ["null"]

    for i in range(1, N+1):
        name = sys.stdin.readline().rstrip()
        name_num[name] = i
        num_name.append(name)

    for _ in range(M):
        request = sys.stdin.readline().rstrip()
        if(name_num[request] != 0):
            print(name_num[request])
        else:
            print(num_name[int(request)])

