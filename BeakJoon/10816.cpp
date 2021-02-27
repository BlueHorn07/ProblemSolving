#include<bits/stdc++.h>
#define MAX 500005
using namespace std;

int N, M;
int arr[MAX], target[MAX];

int rightSearch(int start, int end, int target){
  int mid = (start + end) / 2;
  if(start >= mid){
    return end;
  }
  
  if(arr[mid] > target){
    return rightSearch(start, mid, target);
  }else if(arr[mid] == target){
    return rightSearch(mid, end, target);
  }
}

int leftSearch(int start, int end, int target){
  int mid = (start + end) / 2;
  
  if(start >= end){
    return start;
  }
  
  if(arr[mid] < target){
    return leftSearch(mid+1, end, target);
  }else if(arr[mid] == target){
    return leftSearch(start, mid, target);
  }
}

int bSearch(int start, int end, int target){
  int mid = (start + end) / 2;
  if(start >= end){
    return -1;
  }
  
  if(arr[mid] < target){
    return bSearch(mid+1, end, target);
  }else if(arr[mid] > target){
    return bSearch(start, mid, target);
  }else {
    int leftEnd = leftSearch(0, mid+1, target); // mid+1
    int rightEnd = rightSearch(mid, end, target);
    return rightEnd - leftEnd;
  }
}


int main(){
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }
  
  scanf("%d", &M);
  for(int i=0; i<M; i++){
    scanf("%d", &target[i]);
  }
  
  // sort
  sort(arr, arr+N);
  
  for(int i=0; i<M; i++){
    int out = bSearch(0, N, target[i]);
    if(out == -1){
      printf("0 ");
    }else{
      printf("%d ", out);
    }
    
  }
  
  return 0;
}