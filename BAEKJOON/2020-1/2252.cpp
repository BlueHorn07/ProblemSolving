#include<cstdio>
#include<vector>
#include<queue>

#define VMAX 32001

using namespace std;
vector<int> edges[VMAX];
int RANK[VMAX];
int V, E;

void BFS(){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=1; i<=V; i++){
        if(!RANK[i]){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int front = pq.top();
        pq.pop();
        printf("%d ", front);
        for(int i=0; i<edges[front].size(); i++){
            int adj = edges[front][i];
            RANK[adj] -= 1;
            if(!RANK[adj])
                pq.push(adj);
        }
    }

}


int main(){

    scanf("%d %d", &V, &E);
    for(int i=0; i<E; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        RANK[v] += 1;
    }

    BFS();

    printf("\n");
    return 0;
}