#include<bits/stdc++.h>

#define MAX 1000005
using namespace std;
int arr[MAX];
int N, M;

long long sum;

int bSearch_height(int start, int end, int target) {
  int mid = (start + end) / 2;
  
  if (start >= end) {
    return start;
  }
  
  if (arr[mid] <= target) {
    return bSearch_height(mid + 1, end, target);
  } else {
    return bSearch_height(start, mid, target);
  }
}

int bSearch(int start, int end) {
  int mid = (start + end) / 2;
  
  if (start >= end) {
    return start;
  }
  
  if(mid == 0){
    return 0;
  }
  
  int out = bSearch_height(0, N, mid);
  
  sum = 0;
  for (int i = out; i < N; i++) {
    sum += (arr[i] - mid);
    if(sum > M){
      break;
    }
  }
  
  if (sum < M) {
    return bSearch(start, mid);
  } else if (sum > M) {
    return bSearch(mid + 1, end);
  } else {
    return mid;
  }
}

int main() {
  scanf("%d %d", &N, &M);
  int maxLength = -1;
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    maxLength = max(maxLength, arr[i]);
  }
  
  sort(arr, arr + N);
  
  int out = bSearch(0, maxLength + 1);
  if(out == 0){
    printf("0");
    return 0;
  }
  
  if (sum != M) {
    out -= 1;
  }
  
  printf("%d", out);
  
  return 0;
}