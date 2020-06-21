#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <string.h>

#define MAX 300

using namespace std;

int Prev[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];

int maxFlow(int start, int end){
    int result = 0;
    while(1){
        memset(Prev, -1, sizeof(Prev));
        queue<int> q;
        q.push(start);
        Prev[start] = start;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<edges[curr].size(); i++){
                int adj = edges[curr][i];
                if(Prev[adj] == -1 && capacity[curr][adj] > flow[curr][adj]){
                    Prev[adj] = curr;
                    q.push(adj);
                    if(adj == end) break;
                }
            }
        }
        if(Prev[end] == -1) break;

        for(int v = end; v != start; v = Prev[v]){
            flow[Prev[v]][v] += 1;
            flow[v][Prev[v]] -= 1;
        }
        result += 1;
    }
    return result;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    if(M == 0){
        printf("0\n");
        return 0;
    }    
    for(int i=1; i<=N; i++){
        edges[0].push_back(i);
        edges[i].push_back(0);
        capacity[0][i] = 1;

    }
    /* 1 | 1 ~ N  | N+1 ~ N+N | N+N+1*/
    for(int j=0; j<M; j++){
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(N+b);
        edges[N+b].push_back(a);
        capacity[a][N+b] = 1;
    }
    int end = N+N+1;
    for(int j=N+1; j<end; j++){
        edges[j].push_back(end);
        edges[end].push_back(j);
        capacity[j][end] = 1;
    }
    printf("%d", maxFlow(0, end));
    return 0;
}