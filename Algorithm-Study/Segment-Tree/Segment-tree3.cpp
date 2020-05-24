// 참고 링크: https://youtu.be/Afr0yvd-8bA

#define NMAX (1 << 20)
int tree[2*NMAX]; // 전역 변수로 선언해서 update에서 바로 접근 가능!

// 점 하나만을 갱신
void update(int x, int V, int s, int e){
    if(s==e){
        tree[s] = V;
        return;
    }
    int mid = (s+e)/2;
    if(x <= mid){
        update(x, V, s, mid);
    }else{
        update(x, V, mid+1, e);
    }
}



// 구간 합 쿼리
int sumQuery(int L, int R, int node, int s, int e){
    if(R < s || e < L){
        return 0; // 합이니까 0을 리턴
    }
    if(L <= s && e <= R){
        return tree[node];
    }
    int mid = (s+e)/2;
    int left_sum = sumQuery(L, R, node*2, s, mid);
    int right_sum = sumQuery(L, R, node*2+1, mid+1, e);
    return left_sum + right_sum;
    // 처음에는 tree[node] = left_sum + right_sum 해야 한다고 생각했는데,
    // 이게 점을 갱신하지 않고, 그냥 탐색만 하는 거니까 
    // tree[node] = left_sum + right_sum를 할 필요가 없었음!!

}


/* ------------- 비재귀 구현 ------------- */

// 점 하나를 갱신
void update2(int x, int V){
    x += NMAX - 1;
    tree[x] = V;
    for( x/=2 ; x >= 1; x /= 2){
        tree[x] = tree[2*x] + tree[2*x + 1];
    }
}