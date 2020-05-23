#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

#define Arr vector<long long> 

long long init(Arr &arr, Arr &tree, int node, int s, int e){
    if(s == e){
        tree[node] = arr[s];
        return arr[s];
    }
    else{
        int mid = (s+e) / 2;
        tree[node] = min(init(arr, tree, node*2, s, mid), init(arr, tree, node*2+1, mid+1, e));
        return tree[node];
    }
}

long long minQuery(Arr &tree, int node, int s, int e, int l, int r){
    if (l > e || r < s){
        return LLONG_MAX;
    }
    if(l <= s && e <= r){
        return tree[node];
    }

    int mid = (s+e)/2;
    long long left_min = minQuery(tree, node*2, s, mid, l, r);
    long long right_min = minQuery(tree, node*2+1, mid+1, e, l, r);
    return min(left_min, right_min);
}


int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    Arr nums(N);

    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
    Arr tree(tree_size);

    for(int i=0; i<N; i++){
        scanf("%lld", &nums[i]);
    }

    init(nums, tree, 1, 0, N-1);

    for(int i=0; i<M; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%lld\n", minQuery(tree, 1, 0, N-1, s-1, e-1));
    }

    return 0;
}