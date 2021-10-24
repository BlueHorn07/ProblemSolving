#include<bits/stdc++.h>

using namespace std;
#define MAX 11

int C, n, m;

vector<int> pairs[MAX];

int matching(vector<int> nums) {
  if (nums.size() == 0) {
    return 1;
  }
  
  int sum = 0;
  
  bool haveMatched[MAX][MAX] = {0,};
  int source = nums[0];
  
  for (int j = 0; j < pairs[source].size(); j++) {
    int target = pairs[source][j];
    
    bool isInNum = false;
    for (int k = 0; k < nums.size(); k++) {
      if (nums[k] == target) {
        isInNum = true;
        break;
      }
    }
    
    if(!isInNum){
      continue;
    }
    
    if (!haveMatched[source][target]) {
      haveMatched[source][target] = haveMatched[target][source] = true;
      vector<int> new_nums;
      for (int k = 0; k < nums.size(); k++) {
        if ((nums[k] != source) && (nums[k] != target)) {
          new_nums.push_back(nums[k]);
        }
      }
      sum += matching(new_nums);
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
  
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    nums.push_back(i);
  }
  
  int out = matching(nums);
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