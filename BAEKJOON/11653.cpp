#include<bits/stdc++.h>

using namespace std;

void divide(int num, int divider){
  if(num == 1){
    return;
  }
  if(num % divider == 0){
    printf("%d\n", divider);
    divide(num / divider, divider);
  }else{
    divide(num, divider+1);
  }
}

int main() {
  int N;
  scanf("%d", &N);
  divide(N, 2);
  
  return 0;
}