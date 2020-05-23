N, M = map(int, input().split())

field = []

for i in range(N):
    field.append(str(input()))

visited = [[0 for i in range(M)] for j in range(N)]
visited[0][0] = 1

queue = []
queue.append([0, 0])

while queue:
    fNode_y, fNode_x = queue[0]
    del queue[0]

    if fNode_x + 1 < M and field[fNode_y][fNode_x+1] == '1' and visited[fNode_y][fNode_x+1] == 0:
        queue.append([fNode_y, fNode_x+1])
        visited[fNode_y][fNode_x+1] = visited[fNode_y][fNode_x] + 1

    if fNode_x > 0 and field[fNode_y][fNode_x-1] == '1' and visited[fNode_y][fNode_x-1] == 0:
        queue.append([fNode_y, fNode_x-1])
        visited[fNode_y][fNode_x-1] = visited[fNode_y][fNode_x] + 1

    if fNode_y + 1 < N and field[fNode_y+1][fNode_x] == '1' and visited[fNode_y+1][fNode_x] == 0:
        queue.append([fNode_y+1, fNode_x])
        visited[fNode_y+1][fNode_x] = visited[fNode_y][fNode_x] + 1

    if fNode_y > 0 and field[fNode_y-1][fNode_x] == '1' and visited[fNode_y-1][fNode_x] == 0:
        queue.append([fNode_y-1, fNode_x])
        visited[fNode_y-1][fNode_x] = visited[fNode_y][fNode_x] + 1


print(visited[N-1][M-1])