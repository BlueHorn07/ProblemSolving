#include<cstdio>
#include<queue>
#include<vector>

#define NMAX 100

// distance - node_idx의 key-value 자료형
#define Dist_Node pair<long long, int>


using namespace std;

vector<vector<pair<int, int>>> edges(NMAX, vector<pair<int, int>>(NMAX, make_pair(-1, -1))); // key: vector of (node, weight)

long long dist[NMAX];

void dijkstra(int V, int s){
    for(int i=0; i<V; i++){
        dist[i] = LLONG_MAX;
    }

    dist[s] = 0;

    priority_queue<Dist_Node, vector<Dist_Node>, greater<Dist_Node>> pq;

    for(int i=0; i<V; i++){
        pq.push(make_pair(dist[i], i));
    }

    while(!pq.empty()){
        Dist_Node top = pq.top();
        vector<pair<int, int>> adjacents = edges[top.second];
    }


}

int main(){

}