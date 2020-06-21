#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>

#define MAX 100
#define INF INT_MAX

using namespace std;

int Prev[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];


int maxFlow(int start, int end){
    int result = 0;
    while(1){
        queue<int> q;
        memset(Prev, -1, MAX);
        q.push(start);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto iter = edges[curr].begin(); iter != edges[curr].end(); iter++){
                int adj = *iter;
                if(Prev[1] == -1 && capacity[adj] > flow[adj]){
                    Prev[adj] = curr;
                    q.push(adj);
                }
            }
        }
        if(Prev[end] == -1) break;

        int curFlow = INF;
        for(int v = end; v != start; v = Prev[v]){
            curFlow = min(curFlow, capacity[Prev[v]][v] - flow[Prev[v]][v]);
        }

        for(int v = end; v != start; v = Prev[v]){
            flow[Prev[v]][v] += curFlow;
            flow[v][Prev[v]] -= curFlow;
        }
        result += curFlow;
    }
    return result;
}

int main(){
    int N, P;
    scanf("%d %d", &N, &P);
    for(int i=0; i<P; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges[e].push_back(s);
        capacity[s][e] += 1;
    }
    printf("%d", maxFlow(0, 5));
    return 0;
}