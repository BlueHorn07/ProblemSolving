# Edmonds-Karp Algorithm

[2188번 - 축사배정](https://www.acmicpc.net/problem/2188)

처음에 입력을 통해 edge를 초기화 할 때,
```cpp
for(int i=1; i<=N; i++){
    int n;
    scanf("%d", &n);
    edges[0].push_back(i);
    edges[i].push_back(0);
    capacity[0][i] = 1;
    /* 1 | 1 ~ N  | N+1 ~ N+M | N+M+1*/
    for(int j=0; j<n; j++){
        int m;
        scanf("%d", &m);
        edges[i].push_back(N+m);
        edges[N+m].push_back(i);
        capacity[i][N+m] = 1;
    }
}
```

에서
```cpp
for(int i=1; i<=N; i++){
    int n;
    scanf("%d", &n);
    edges[0].push_back(i);
    edges[i].push_back(0);
    capacity[0][i] = 1;
    /* 1 | 1 ~ N  | N+1 ~ N+M | N+M+1*/
    for(int j=0; j<n; j++){
        int m;
        scanf("%d", &m);
        edges[i].push_back(N+m);
        // edges[N+m].push_back(i);
        capacity[i][N+m] = 1;
    }
}
```

역으로 가는 edge를 설정을 안 해주니, 틀리는 구만!!

bipartite라서 backward edge를 설정할 필요가 없을 줄 알았는데, bipartite도 필요하군!