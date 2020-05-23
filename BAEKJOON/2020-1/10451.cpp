#include<cstdio>

#define VMAX 1001

using namespace std;

class DisjointSet {
    private :
        int parent[VMAX];
        int cnt = 0;
    public:
        DisjointSet(int N){
            cnt = N;

            for(int i=0; i<=N; i++){
                parent[i] = i;
            }
        }
        int Find(int v){
            if(v != parent[v])
                parent[v] = Find(parent[v]);
            return parent[v];
        }
        void Union(int v1, int v2){
            int rootV1 = Find(v1);
            int rootV2 = Find(v2);
            if(rootV1 == rootV2) {
                return;
            }
            parent[rootV1] = rootV2;
            cnt--;
        }
        int NumOfDS(){
            return cnt;
        }
};

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        int n;
        scanf("%d", &n);
        DisjointSet DS(n);
        for(int i=0; i<n; i++){
            int u;
            scanf("%d", &u);
            if(i+1 != u)
                DS.Union(i+1, u);
        }
        printf("%d\n", DS.NumOfDS());

    }
    return 0;
}