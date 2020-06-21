#include<cstdio>
#include<vector>
#include<queue>

#define MAX 200001

using namespace std;
vector<int> edges[MAX];
int visit[MAX];

void bfs(int start){
    queue<int> q;
    int color = 1;
    
    visit[start] = color;
    q.push(start);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        if(visit[curr] == 1)
            color = 2;
        else 
            color = 1;
        for(int i=0; i<edges[curr].size(); i++){
            int adj = edges[curr][i];
            if(!visit[adj]){
                visit[adj] = color;
                q.push(adj);
            }
        }
    }

}

bool isBartite(int V){
    for(int i=1; i<=V; i++){
        if(visit[i]){
            for(int j=0; j<edges[i].size(); j++){
                if(visit[i] == visit[edges[i][j]])
                    return false;
            }
        }

    }
    return true;
}

int main(){
    int K;
    scanf("%d", &K);
    for(int k=0; k<K; k++){
        int V, E;
        scanf("%d%d", &V, &E);
        for(int i=0; i<E; i++){
            int s, e;
            scanf("%d%d", &s, &e);
            edges[s].push_back(e);
            edges[e].push_back(s);
        }
        for(int i=1; i<=V; i++){
            if(!visit[i])
                bfs(i);
        }
        if(isBartite(V))
            printf("YES\n");
        else
            printf("NO\n");
        fill(visit, visit+V+1, 0);
        for(int i=1; i<=V; i++){
            edges[i].clear();
        }
    }

    return 0;
}