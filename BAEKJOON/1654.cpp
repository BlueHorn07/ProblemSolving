#include<bits/stdc++.h>

using namespace std;
#define MAX 10005
int K, N;
long lengths[MAX];

long binarySearch(long start, long end) {
  long mid = (start + end) / 2;
  
  if (start >= mid) {
    return start;
  }
  
  long long midCnt = 0;
  for(int i=0; i<K; i++){
    midCnt += (lengths[i] / mid);
    if(N <= midCnt){
      break;
    }
  }

  if(N > midCnt){
    return binarySearch(start, mid);
  }
  else {
    return binarySearch(mid, end);
  }
}

int main() {
  scanf("%d %d", &K, &N);
  long maxLength = -1;
  for (int i = 0; i < K; i++) {
    scanf("%lld", &lengths[i]);
    maxLength = max(maxLength, lengths[i]);
  }
  
  long out = binarySearch(1, maxLength+1);
  // end를 maxLength+1로 잡아줘야 함!!
  // 왜냐하면, 값의 상한이 maxLenght까지라서 mid를 취했을 때, maxLenght까지 갈 수 있도록 이렇게 해야 함!!
  printf("%ld\n", out);
  
  return 0;
}