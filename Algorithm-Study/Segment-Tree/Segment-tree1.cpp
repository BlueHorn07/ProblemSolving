#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


// Generate Interval Sum Segment Tree, and
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start == end)
        return tree[node] = a[start];
    else{
        long long left_child = init(a, tree, node*2, start, (start+end)/2);
        long long right_child = init(a, tree, node*2 + 1, (start+end)/2 + 1, end);
        return tree[node] = left_child + right_child;
    }
}

// 구간합 Segment Tree
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    long long left_sum = sum(tree, node*2, start, (start+end)/2, left, right);
    long long right_sum = sum(tree, node*2+1, (start+end)/2+1, end, left, right);
    return left_sum + right_sum;
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    // index가 [s, e]에 포함되지 않을 때,
    if (index < start || end < index){
        return;
    }
    // index가 [s, e]에 포함될 때,
    tree[node] += diff;
    if(start != end){
        int mid = (start + end) / 2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, mid+1, end, index, diff);
    }
}


int main(){
    long long N, M, K;
    scanf("%lld %lld %lld", &N, &M, &K);

    vector<long long> nums;
    nums.assign(N, 0);

    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
    vector<long long> tree;
    tree.assign(tree_size, 0);

    for(int i=0; i<N; i++){
        scanf("%lld", &nums[i]);
    }

    init(nums, tree, 1, 0, N-1);

    for(int i=0; i<M+K; i++){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        // update
        if(a == 1){
            long long diff = c - nums[b-1];
            nums[b-1] = c;
            update(tree, 1, 0, N-1, b-1, diff);
        }else{
            printf("%lld\n", sum(tree, 1, 0, N-1, b-1, c-1));
        }
    }

    return 0;
}
