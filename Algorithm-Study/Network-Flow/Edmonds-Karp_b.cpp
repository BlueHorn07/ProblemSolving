#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#include <string.h>

#define MAX 2010

using namespace std;

int Prev[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];

int maxFlow(int start, int end){
    int result = 0;
    while(1){
        queue<int> q;
        q.push(start);
        fill(Prev, Prev+end+2, -1);
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
    int end = N+M+1;
    for(int j=N+1; j<end; j++){
        edges[j].push_back(end);
        edges[end].push_back(j);
        capacity[j][end] = 1;
    }
    printf("%d", maxFlow(0, end));
    return 0;
}