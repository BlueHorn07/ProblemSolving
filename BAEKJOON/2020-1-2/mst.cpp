#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define VMAX 10001

using namespace std;


int Rank[VMAX];
int Parent[VMAX];

void Makeset(int node){
    Parent[node] = node;
    Rank[node] = 0;
}

int Find(int node){
    if (node != Parent[node]){
        Parent[node] = Find(Parent[node]);
    }
    return Parent[node];
}

void Union(int node1, int node2){
    int root1 = Find(node1);
    int root2 = Find(node2);
    if( root1 == root2)
        return;
    if (root1 > root2){
        Parent[root2] = root1;
    }else{
        Parent[root1] = root2;
        if(Rank[root1] == Rank[root2])
            Rank[root2] = Rank[root2] + 1;
    }
}

// weight, edge
vector<pair<int, pair<int, int>>> edges;


void mst(int V, int E){
    for(int i=0; i<V; i++){
        Makeset(i);
    }
    vector<pair<int, int>> X;

    // Sort edges by weights
    sort(edges.begin(), edges.end());
    long long sum = 0;
    for(int i=0; i<E; i++){
        pair<int, int> vertex_pair = edges[i].second;
        if(Find(vertex_pair.first) != Find(vertex_pair.second)){
            sum += edges[i].first;
            X.push_back(vertex_pair);
            Union(vertex_pair.first, vertex_pair.second);
        }
    }
    printf("%lld\n", sum);
}



int main(){
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i=0; i<E; i++){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        edges.push_back(make_pair(w, make_pair(s-1, e-1)));
    }

    mst(V, E);

    return 0;
}