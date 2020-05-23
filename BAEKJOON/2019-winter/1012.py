T = int(input())

for t in range(T):
    M, N, K = map(int, input().split())

    field = [[0 for i in range(M)] for j in range(N)]
    visited = [[0 for i in range(M)] for j in range(N)]

    for i in range(K):
        x, y = map(int, input().split())
        field[y][x] = 1
    # DFS
    cnt = 0

    for i in range(N): # y
        for j in range(M): # x
            if field[i][j] == 1 and visited[i][j] == 0:
                cnt += 1
                stack = []
                stack.append([i, j])

                while stack :
                    tNode = stack[-1]
                    stack.pop()

                    tNode_y = tNode[0]
                    tNode_x = tNode[1]
                    
                    if visited[tNode_y][tNode_x] == 0:
                        if tNode_x + 1 < M and field[tNode_y][tNode_x+1] == 1 and visited[tNode_y][tNode_x+1] == 0:
                            stack.append([tNode_y, tNode_x+1])
                        if tNode_x - 1 >= 0 and field[tNode_y][tNode_x-1] == 1 and visited[tNode_y][tNode_x-1] == 0:
                            stack.append([tNode_y, tNode_x-1])
                        if tNode_y + 1 < N and field[tNode_y+1][tNode_x] == 1 and visited[tNode_y+1][tNode_x] == 0:
                            stack.append([tNode_y+1, tNode_x])                            
                        if tNode_y - 1 >= 0 and field[tNode_y-1][tNode_x] == 1 and visited[tNode_y-1][tNode_x] == 0:
                            stack.append([tNode_y-1, tNode_x])
                        visited[tNode_y][tNode_x] = 1

    print(cnt)                
                                            