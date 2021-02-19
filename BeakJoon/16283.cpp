#include<bits/stdc++.h>

using namespace std;

int a, b, n, w;

int main() {
  scanf("%d %d %d %d", &a, &b, &n, &w);
  
  int x, y;
  
  if (a == b) {
    if(w % a != 0 || w / a != n){
      printf("-1\n");
    }else{
      if (n == 2) {
        printf("1 1\n");
      } else {
        printf("-1\n");
      }
    }
  } else {
    if ((n * a - w) % (a - b) != 0) {
      printf("-1\n");
    } else {
      y = (n * a - w) / (a - b);
      if ((n - y) <= 0 || y <= 0) {
        printf("-1\n");
      } else {
        printf("%d %d\n", n - y, y);
      }
    }
  }
  return 0;
}