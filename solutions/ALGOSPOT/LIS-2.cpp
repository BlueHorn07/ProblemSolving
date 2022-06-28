#include <cstdio>
#include <climits>
#include <algorithm>

#define MAX 505

using namespace std;

int bSearch(int s, int e, int target, int arr[]) {
  if (s >= e) return s;
  
  int mid = (s + e) / 2;

  if (target == arr[mid]) {
    return mid;
  }
  else if (target < arr[mid]) {
    return bSearch(s, mid, target, arr);
  } else {
    return bSearch(mid + 1, e, target, arr);
  }
}

void solve() {
  int N;
  scanf("%d", &N);

  int arr[MAX];
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }

  int LIS_last[MAX];
  fill_n(LIS_last, N, INT_MAX); // -1: not reached
  LIS_last[0] = arr[0];

  int k = 1;
  for(int i=1; i<N; i++) {
    int val = arr[i];

    // binary search
    int idx = bSearch(0, k, val, LIS_last);
    LIS_last[idx] = val;

    k = max(k, idx + 1);
  }

  printf("%d\n", k);
}

int main() {
  int C;
  scanf("%d", &C);

  for(int t = 0; t < C; t++) {
    solve();
  }

  return 0;
}