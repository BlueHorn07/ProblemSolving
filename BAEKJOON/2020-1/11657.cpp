#include<cstdio>
#include<climits>
#include<vector>
#include<unordered_map>
#include<iostream>

#define INF LLONG_MAX

using namespace std;

int N, M;

unordered_map<int, vector<pair<int, int>>> edges;
vector<long long> dist;

void BellmanFord(int start, bool NegCycleTest){
    // initialize
    if(!NegCycleTest){
        for(int i=0; i<N; i++){
            dist.push_back(INF);
        }
        dist[start] = 0;
    }

    for(int j=0; j < N-1; j++){ // |V|-1 iteration
        for(int u=0; u<N; u++){ // |E| edges iteration (u, v)
            if(!edges[u].empty()){ // if there are edges, 
                for(int k=0; k < edges[u].size(); k++){
                    int v = edges[u][k].first;
                    int cost = edges[u][k].second;
                    if(dist[u] != INF && dist[v] > dist[u] + cost){
                        if(NegCycleTest){
                            printf("-1\n");
                            exit(0);
                        }
                        dist[v] = dist[u] + cost;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    
    int A, B, C;
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &A, &B, &C);
        A -= 1;
        B -= 1;
        edges[A].push_back(make_pair(B, C));
    }

    BellmanFord(0, false);
    BellmanFord(0, true);

    for(int i=1; i<N; i++){
        if(dist[i] == INF){
            printf("-1\n");
        }else{
            printf("%lld\n", dist[i]);
        }
    }

    return 0;
}
