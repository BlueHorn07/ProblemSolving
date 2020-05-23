N, M, V = map(int, input().split())

edges = [ [] for i in range(N+1) ]

for m in range(M):
    s, e = map(int, input().split())
    edges[s].append(e)
    edges[e].append(s)

for n in range(N+1):
    edges[n].sort()

# visited node check list
visited = [False for i in range(N+1)]

dfs_result = []
bfs_result = []

## DFS
stack = []
stack.append(V)

while stack :
    tNode = stack[-1]
    stack.pop()

    if visited[tNode] == False:
        visited[tNode] = True
        for i in reversed(edges[tNode]) :
            if visited[i] == False:
                stack.append(i)

        dfs_result.append(tNode)

print(" ".join(map(str, dfs_result)))

## visited check list initialization
visited = [False for i in range(N+1)]

## BFS
queue = []
queue.append(V)

while queue :
    fNode = queue[0]
    del queue[0]

    if visited[fNode] == False:
        visited[fNode] = True
        for i in edges[fNode]:
            if visited[i] == False:
                queue.append(i)
        bfs_result.append(fNode)

print(" ".join(map(str, bfs_result)))
