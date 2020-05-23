import sys

N = int(sys.stdin.readline().rstrip())

graph = [[] for i in range(N)]

for i in range(N):
    row_input = list(map(int, sys.stdin.readline().rstrip().split()))
    for j in range(N):
        if row_input[j] == 1:
            graph[i].append(j)

path = [[0 for i in range(N)] for j in range(N)]

for i in range(N):
    # DFS
    visited = [0 for j in range(N)]

    stack = []
    stack.append(i)

    while stack:
        tNode = stack[-1]
        stack.pop()
        if visited[tNode] == 0:
            for j in graph[tNode]:
                if i == j:
                    path[i][i] = 1
                if visited[j] == 0:
                    stack.append(j)
                    path[i][j] = 1
            visited[tNode] = 1

for i in range(N):
    for j in range(N):
        print(path[i][j], end=" ")
    print()
