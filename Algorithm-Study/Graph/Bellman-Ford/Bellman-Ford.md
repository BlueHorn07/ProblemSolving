## Bellman-Ford Algorithm

일단 기존 다익스트라와 구현상의 차이점은 `while`문 없이 두 번의 `for`문으로 start 노드에서 다른 모든 노드까지의 거리를 구한다는 것이다!!!

그리고 Bellman-Ford는 Negative Cycle이 없는 Graph에 대해서만 올바른 shortest-path 값을 줄 수 있다. 그래서 Negative Cycle이 있는지 없는지 추가로 확인을 해줘야 한다!!