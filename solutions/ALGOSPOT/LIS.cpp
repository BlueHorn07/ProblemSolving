#include <cstdio>
#include <algorithm>

#define MAX 505

using namespace std;

void solve() {
  int N;
  scanf("%d", &N);

  int arr[MAX];
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
  }

  int dp[MAX];
  fill_n(dp, N, 1);

  int max_val = -1;
  for(int i=0; i<N; i++) {
    for(int j=0; j<i; j++) {
      if (arr[i] < arr[j]) continue;
      dp[i] = max(dp[i], dp[j] + 1);
    }
    max_val = max(max_val, dp[i]);
  }
  printf("%d\n", max_val);
}

int main() {
  int C;
  scanf("%d", &C);

  for(int t = 0; t < C; t++) {
    solve();
  }

  return 0;
}