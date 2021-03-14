#include<bits/stdc++.h>

#define MAX 10005
using namespace std;

bool isPrime[MAX];

void goldbach() {
  int n;
  scanf("%d", &n);
  
  for (int i = 2; i <= n / 2 + 1; i++) {
    if (!isPrime[i]) continue; // prime이 아니라면, 패스
    
    for (int j = i + i; j <= n; j += i) {
      isPrime[j] = false;
    }
  }
  
  int ans = 2;
  
  for (int i = 2; i <= n / 2; i++) {
    if (!isPrime[i]) continue; // prime이 아니면 패스
    if (!isPrime[n - i]) continue; // conjugate가 prime이 아니면 패스
    
    ans = i;
  }
  
  printf("%d %d\n", ans, n - ans);
}

int main() {
  int T;
  scanf("%d", &T);
  
  fill_n(isPrime, MAX, true);
  
  isPrime[0] = false;
  isPrime[1] = false;
  
  for (int t = 0; t < T; t++) {
    goldbach();
  }
  
  return 0;
}