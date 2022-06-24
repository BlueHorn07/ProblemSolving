#include<bits/stdc++.h>

#define MAX 21
using namespace std;

int C, H, W;

int CoverPatterns[12][2][2] = {
    {{-1, 0},  {-1, -1}},
    {{-1, 0},  {-1, +1}},
    {{+1, 0},  {+1, +1}},
    {{+1, 0},  {+1, -1}},
    {{0,  -1}, {-1, -1}},
    {{0,  -1}, {+1, -1}},
    {{0,  +1}, {+1, +1}},
    {{0,  +1}, {-1, +1}},

    {{+1,  0}, {0, +1}},
    {{-1,  0}, {0, -1}},
    {{+1,  0}, {0, -1}},
    {{-1,  0}, {0, +1}},
};

bool isRange(int y, int x) {
  return (0 <= y) && (y < H) && (0 <= x) && (x < W);
}

int search(bool board[MAX][MAX]) {
  
  int Empty_y = -1, Empty_x = -1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (board[i][j]) {
        Empty_y = i, Empty_x = j;
        break;
      }
    }
    if(Empty_y != -1) break;
  }
  
  if (Empty_y == -1) return 1; // 꽉찬 보드!
  
  int sum = 0;
  
  for (int i = 0; i < 12; i++) {
    int y1 = Empty_y + CoverPatterns[i][0][0], x1 = Empty_x + CoverPatterns[i][0][1];
    int y2 = Empty_y + CoverPatterns[i][1][0], x2 = Empty_x + CoverPatterns[i][1][1];

    if (isRange(y1, x1) && isRange(y2, x2)) {
      if (board[y1][x1] && board[y2][x2]) {
        board[Empty_y][Empty_x] = board[y1][x1] = board[y2][x2] = false;
        sum += search(board);
        board[Empty_y][Empty_x] = board[y1][x1] = board[y2][x2] = true;
      }
    }
  }
  return sum;
}


void testCase() {
  scanf("%d %d", &H, &W);
  bool startBoard[MAX][MAX];
//  fill_n(startBoard, MAX * MAX, false);
  
  for (int i = 0; i < H; i++) {
    char line[MAX];
    scanf("%s", line);
    for (int j = 0; j < W; j++) {
      startBoard[i][j] = (line[j] == '.');
    }
  }

  int out = search(startBoard);
  printf("%d\n", out);
}

int main() {
  scanf("%d", &C);
  for (int i = 0; i < C; i++) {
    testCase();
  }
  return 0;
}