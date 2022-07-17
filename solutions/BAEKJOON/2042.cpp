#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

typedef long long llong;

llong init(vector<llong> &arr, vector<llong> &tree, int node, int start, int end) {
  if (start == end) // 리프 노드임.
    return tree[node] = arr[start];
  
  int mid = (start + end) / 2;
  
  llong left = init(arr, tree, node * 2, start, mid);
  llong right = init(arr, tree, node * 2 + 1, mid + 1, end);
  
  tree[node] = left + right;
  return tree[node];
}

// start, end는 node가 커버하는 범위를 뜻함.
llong sum(vector<llong> &tree, int node, int start, int end, int left, int right) {
  // query하는 범위가 겹치지 않음.
  if (left > end || right < start) 
    return 0;
  
  // 구해야하는 합의 범위는 [left,right]인데, 
  // [start,end]는 그 범위에 모두 포함되고, 
  // 그 node의 자식도 모두 포함되기 때문에 
  // 더 이상 호출을 하는 것은 비효율적입니다. 
  if (left <= start && end <= right)
    return tree[node];
  
  int mid = (start + end) / 2;
  llong leftSum = sum(tree, node * 2, start, mid, left, right);
  llong rightSum = sum(tree, node * 2 + 1, mid+1, end, left, right);
  
  return leftSum + rightSum;
}

void update(vector<llong> &tree, int node, int start, int end, int index, llong diff) {
  if (index < start || end < index) return;
  
  tree[node] += diff;
  
  // 리프 노드는 start == end임.
  // 그러나 리프가 아니라면, 아래의 자식노드도 업데이트 해줘야 함.
  if (start != end) {
    int mid = (start + end) / 2;
    update(tree, node * 2, start, mid, index, diff);
    update(tree, node * 2 + 1, mid+1, end, index, diff);
  }
    
}


int main() {
  llong N, M, K;
  scanf("%lld %lld %lld", &N, &M, &K);
  
  vector<llong> arr;
  
  llong num;
  for (int i=0; i<N; i++){
    scanf("%lld", &num);
    arr.push_back(num);
  }
  
  // Segment Tree
  int h = (int) ceil(log2(N));
  int tree_size = (1 << (h+1));
  
  vector<llong> tree;
  tree.assign(tree_size, 0);
  
  init(arr, tree, 1, 0, N-1);
  
  
  // Query
  llong a, b, c;
  for (int i=0; i<M+K; i++) {
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a == 1) {
      llong diff = c - arr[b - 1];
      arr[b-1] = c;
      update(tree, 1, 0, N-1, b - 1, diff);
    } else {
      llong ret = sum(tree, 1, 0, N-1, b - 1, c - 1);
      printf("%lld\n", ret);
    }
  }
  

}