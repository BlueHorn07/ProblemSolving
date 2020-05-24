## Dijkstra's Algorithm


주의!!
python에서 다익스트라 쓸 때, 
``` python
import heapq

pq = []
heapq.heappush(pq, (0, s))
top = heapq.heappop(pq)
```

이런 식으로 사용해야 함!!

뭔가
``` python
from queue import PriorityQueue

pq = PriorityQueue()
```
하니까 뭔가 잘 안 되었던 것 같음 ㅜㅠㅜ

구현이 좀 다른 건가??


<hr>

다익스트라는 2차원 벡터 배열이 필요한데, 처음에 어떻게 초기화할지 막막해서 지금가지 `unordered_map`이라는 우회 방법을 사용했었다.

그런데 찾아보니 https://sunnyholic.com/93

``` cpp
vector<vector<int>> arr(6, vector<int>(5, 0));
```
과 같은 방식으로 초기화를 진행할 수 있었다!!!!
(혁신적이군!!)