#include<cstdio>
#include<queue>
#include<cstdlib>
#include<vector>

using namespace std;

#define NUM 100


int main(){
    int n;
    scanf("%d", &n);
    int s, e;
    scanf("%d %d", &s, &e);
    s -= 1;
    e -= 1;
    int m;
    scanf("%d", &m);

    vector<int> edges[NUM];
    int* dist = (int*)malloc(n * sizeof(int));
    bool* visit = (bool*)malloc(n * sizeof(bool));

    for(int i=0; i<m; i++){
        int se, ee;
        scanf("%d %d", &se, &ee);
        edges[se-1].push_back(ee-1);
        edges[ee-1].push_back(se-1);
    }

    dist[s] = 0;
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i=0; i<edges[front].size(); i++){
            int node = edges[front][i];
            if(node == e){
                printf("%d\n", dist[front] + 1);
                return 0;
            }
            if (!visit[node]){
                q.push(node);
                visit[node] = true;
                dist[node] = dist[front] + 1;
            }
        }
    }
    printf("-1\n");

    return 0;
}

