#include<bits/stdc++.h>

using namespace std;
#define MAX 11

int C, n, m;

vector<int> pairs[MAX];

int matching(bool taken[10]) {
  int source = -1;
  for(int i=0; i<n; i++){
    if(!taken[i]){
      source = i;
      break;
    }
  }
  
  if(source == -1) return 1; // 매칭 완료!
  int sum = 0;
  // 매칭할 녀석 선택
  for(int i=0; i<pairs[source].size(); i++){
    int target = pairs[source][i];
    if(!taken[target]){
      taken[source] = taken[target] = true;
      sum += matching(taken);
      taken[source] = taken[target] = false;
    }
  }
  return sum;
}

void testCase() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    pairs[s1].push_back(s2);
    pairs[s2].push_back(s1);
  }
  
  bool taken[10];
  fill_n(taken, 10, 0);
  
  int out = matching(taken);
  printf("%d\n", out);
  
  for (int i = 0; i < n; i++) {
    pairs[i].clear();
  }
}

int main() {
  scanf("%d", &C);
  for (int i = 0; i < C; i++) {
    testCase();
  }
  return 0;
}