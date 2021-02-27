#include<bits/stdc++.h>

#define MAX 10005

using namespace std;

int main() {
  int M, N;
  scanf("%d %d", &M, &N);
  bool isPrime[MAX];
  fill_n(isPrime, N+1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  
  for (int i = 2; i <= N; i++) {
    if(isPrime[i]){
      for (int j = i+i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }
  long long sum = 0;
  int minPrime = N;
  
  for (int i = M; i <= N; i++) {
    if (isPrime[i]) {
      sum += i;
      minPrime = min(minPrime, i);
    }
  }
  
  if (sum == 0) {
    printf("-1");
  } else {
    printf("%lld\n", sum);
    printf("%d", minPrime);
  }
  
  return 0;
}