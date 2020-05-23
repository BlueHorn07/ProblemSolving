import sys
import heapq

INF = 1000000000000


def dijkstra(s, e, N):
    pq = []
    
    dist[s] = 0

    heapq.heappush(pq, (0, s))

    while(pq):
        dist_top, top = heapq.heappop(pq)
        #print(dist_top, top, pq.qsize())
        if(top == e):
            print(dist[top])
            break
        for adj in edges[top]:
            v, w = adj
            if(dist_top + w < dist[v]):
                dist[v] = dist_top + w
                heapq.heappush(pq, (dist[v], v))


N = int(sys.stdin.readline().rstrip())
M = int(sys.stdin.readline().rstrip())

edges = [[] for _ in range(N+1)]

for _ in range(M):
    s, e, w = map(int, sys.stdin.readline().rstrip().split())
    edges[s].append((e, w))
    
dist = [INF] * (N+1)
S, E = map(int, sys.stdin.readline().rstrip().split())
dijkstra(S, E, N)

