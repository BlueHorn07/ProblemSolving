from copy import deepcopy
import sys

N = int(sys.stdin.readline().rstrip())

board = [[0 for i in range(N+2)] for j in range(N+2)]

K = int(sys.stdin.readline().rstrip())

for k in range(K):
    r, c = map(int, sys.stdin.readline().rstrip().split())
    board[r][c] = 1

L = int(sys.stdin.readline().rstrip())
order = []

for l in range(L):
    order.append(input().split())

order = order[::-1]

#print(int(order[-1][0]))


sec = 0
head = [0, 0]

# deque-head, deque-tail
snake = [[1, 1], [1, 1]]

head_direct = 0 # ['R', 'D', 'L', 'U']

while True:
    # direction read
    if order and int(order[-1][0]) == sec:
        snake.insert(0, (deepcopy(snake[0])))
        if order[-1][1] == 'L': #turn left
            head_direct = (head_direct - 1)%4
        else: #turn right
            head_direct = (head_direct + 1)%4
        order.pop()

    sec += 1

    # Go
    if head_direct == 0:
        snake[0][1] += 1
    elif head_direct == 1:
        snake[0][0] += 1
    elif head_direct == 2:
        snake[0][1] -= 1
    elif head_direct == 3:
        snake[0][0] -= 1

    if board[snake[0][0]][snake[0][1]] == 2:
        break
    else:
        pass

    # Wall DIE
    if snake[0][0] == 0 or snake[0][0] > N or snake[0][1] == 0 or snake[0][1] > N:
        break
    
    # Eat APPLE
    if board[snake[0][0]][snake[0][1]] == 1:
        # Tail Doesn't Move
        pass
    else:
        if len(snake) >= 3 and snake[-1] == snake[-2]:
            snake.pop()
        board[snake[-1][0]][snake[-1][1]] = 0
        # Move Snake Tail
        if (snake[-2][0] - snake[-1][0]) > 0:
            snake[-1][0] += 1
        elif (snake[-2][0] - snake[-1][0]) < 0:
            snake[-1][0] -= 1

        if (snake[-2][1] - snake[-1][1]) > 0:
            snake[-1][1] += 1
        elif (snake[-2][1] - snake[-1][1]) < 0:
            snake[-1][1] -= 1
        

    board[snake[0][0]][snake[0][1]] = 2
    
print(sec)