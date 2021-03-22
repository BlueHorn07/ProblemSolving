#include<bits/stdc++.h>

#define MAX 303

using namespace std;

int pattern[4][2] = {
    {+1, 0},
    {-1, 0},
    {0,  +1},
    {0,  -1}
};
int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int ice_cnt;

void melt() {
  int tmp_board[MAX][MAX] = {0, };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) continue;
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int dy = pattern[k][0], dx = pattern[k][1];
        if (i + dy >= 0 && i + dy < N && j + dx >= 0 && j + dx < M) {
          if (board[i + dy][j + dx] == 0) cnt += 1;
        }
      }
      tmp_board[i][j] = max(0, board[i][j] - cnt);
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      board[i][j] = tmp_board[i][j];
    }
  }
}

void dfs(int y, int x) {
  visited[y][x] = true;
  
  for (int i = 0; i < 4; i++) {
    int dy = pattern[i][0], dx = pattern[i][1];
    if (y + dy >= 0 && y + dy < N && x + dx >= 0 && x + dx < M) {
      if (board[y + dy][x + dx] == 0) continue;
      if (visited[y + dy][x + dx]) continue;
      dfs(y + dy, x + dx);
    }
  }
}

void solve() {
  int turn = 0;
  
  while (true) {
    ice_cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] == 0) continue;
        if (visited[i][j]) continue;
        ice_cnt += 1;
        dfs(i, j);
      }
    }
  
    if (ice_cnt == 0) {
      printf("0");
      break;
    }
  
    if (ice_cnt >= 2) {
      printf("%d", turn);
      break;
    }
    
    melt();
    turn += 1;
    
    fill(&visited[0][0], &visited[MAX][MAX], false);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  
  solve();
  
  return 0;
}