#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dp[105][105];

bool match(int wi, int si, const string& w, const string& s) {
  int& ret = dp[wi][si];
  if (ret != -1) return ret;

  while((wi < w.size() && si < s.size())
          && (w[wi] == s[si] || w[wi] == '?')) {
    wi += 1;
    si += 1;
  }

  // 패턴을 끝까지 읽었다면
  if (wi == w.size()) {
    ret = (si == s.size());
    return ret; // 문자열도 끝까지 읽었어야 매칭됨!
  }

  // 패턴이 아직 남았는데, 종료됨

  // '*'를 마주쳤다면?
  if (w[wi] == '*') {
    for(int skip = 0; si + skip <= s.size(); skip++){
      if (match(wi + 1, si + skip,  w, s)) {
        ret = 1;
        return true;
      }
    }
  }

  ret = 0;
  return false; // '*' 때문에 종료된게 아니라면 미스매치 or 문자열이 먼저 끝난 경우임.
}

void solve(){
  string pattern;
  cin >> pattern;

  int targetN;
  scanf("%d", &targetN);

  vector<string> matched;

  for(int i=0; i<targetN; i++){
    string target;
    cin >> target;

    fill_n(&dp[0][0], 105 * 105, -1);

    if (match(0, 0, pattern, target)) {
      matched.push_back(target);
    }
  }

  sort(matched.begin(), matched.end());

  for(int i=0; i < matched.size(); i++) {
    cout << matched[i] << endl;
  }
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; t++){
    solve();
  }

  return 0;
}

