N = int(input())
E = int(input())

edges = [[] for i in range(N+1)]

for i in range(E):
    s, e = map(int, input().split())
    edges[s].append(e)
    edges[e].append(s)

visited = [False for i in range(N+1)]

cnt = -1

stack = []
stack.append(1)

while stack :
    tNode = stack[-1]
    stack.pop()

    if visited[tNode] == False:
        visited[tNode] = True
        for v in edges[tNode]:
            stack.append(v)
            
        cnt += 1
        

print(cnt)
