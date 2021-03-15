#include<bits/stdc++.h>

#define MAX 105
using namespace std;

int pattern[6][3] = {
    {-1, 0,  0},
    {1,  0,  0},
    {0,  -1, 0},
    {0,  1,  0},
    {0,  0,  -1},
    {0,  0,  1}
};

int M, N, H;
int box[MAX][MAX][MAX];
queue<tuple<int, int, int>> q;

void bfs() {
  while (!q.empty()) {
    tuple<int, int, int> front = q.front();
    q.pop();
    int h = get<0>(front);
    int i = get<1>(front);
    int j = get<2>(front);
    
    for (int k = 0; k < 6; k++) {
      int dh = pattern[k][0], di = pattern[k][1], dj = pattern[k][2];
      if ((h + dh >= 0 && h + dh < H) && (i + di >= 0 && i + di < N) && (j + dj >= 0 && j + dj < M)) {
        if (!box[h + dh][i + di][j + dj]) {
          q.push(make_tuple(h + dh, i + di, j + dj));
          box[h + dh][i + di][j + dj] = box[h][i][j] + 1;
        }
      }
    }
  }
  
}

int main() {
  scanf("%d %d %d", &M, &N, &H);
  for (int h = 0; h < H; h++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%d", &box[h][i][j]);
        // 0 익은
        // 1 안 익은
        // -1 들어있지 x
        if (box[h][i][j] == 1) {
          q.push(make_tuple(h, i, j));
        }
      }
    }
  }
  
  
  bfs();
  
  int maxDay = -1;
  
  for (int h = 0; h < H; h++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (box[h][i][j] == 0) {
          printf("-1");
          return 0;
        }
        
        maxDay = max(box[h][i][j], maxDay);
      }
    }
  }
  
  if (maxDay == -1) {
    printf("0");
  } else {
    printf("%d", maxDay - 1);
  }
  return 0;
}