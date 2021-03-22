#include<bits/stdc++.h>
#define NUM 4

using namespace std;

int x[NUM], y[NUM];
int xmin, ymin, xmax, ymax;

int main() {
  scanf("%d %d", &x[0], &y[0]);
  xmin = xmax = x[0];
  ymin = ymax = y[0];
  
  scanf("%d %d", &x[1], &y[1]);
  xmin = min(xmin, x[1]);
  xmax = max(xmax, x[1]);
  ymin = min(ymin, y[1]);
  ymax = max(ymax, y[1]);
  
  scanf("%d %d", &x[2], &y[2]);
  xmin = min(xmin, x[2]);
  xmax = max(xmax, x[2]);
  ymin = min(ymin, y[2]);
  ymax = max(ymax, y[2]);
  
  int coord[4][2] = {
      {xmin, ymin}, {xmin, ymax},
      {xmax, ymax}, {xmax, ymin}
  };
  
  for(int i=0; i<4; i++){
    bool isExist = false;
    for(int j=0; j<3; j++){
      if(x[j] == coord[i][0] && y[j] == coord[i][1]) {
        isExist = true;
        break;
      }
    }
    if(!isExist) {
      printf("%d %d", coord[i][0], coord[i][1]);
      return 0;
    }
  }
  
  return 0;
}