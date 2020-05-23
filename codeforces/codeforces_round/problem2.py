N = int(input())

beauties = list(map(int, input().split()))


adjacency_list = [[] for i in range(N)]

for i in range(N):
    for j in range(i+1, N):
        if (j - i) == (beauties[j] - beauties[i]):
            adjacency_list[i].append(j)

visited = [beauties[i] for i in range(N)]

checked = [0 for i in range(N)]

max_beuty = 0
cnt = 0

for i in range(N):
    if adjacency_list[i] and checked[i] == 0:
        queue = []
        queue.append(i)

        while queue:
            fNode = queue[0]
            del queue[0]
            
            for j in adjacency_list[fNode]:
                queue.append(j)
                checked[j] = 1
                if visited[j] < visited[fNode] + beauties[j]:
                    visited[j] = visited[fNode] + beauties[j]
                    
print(max(visited))    