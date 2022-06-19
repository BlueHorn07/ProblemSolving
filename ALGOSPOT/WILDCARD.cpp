#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool match(const string& w, const string& s) {
  int pos = 0;
  while((pos < w.size() && pos < s.size())
          && (w[pos] == s[pos] || w[pos] == '?')) {
    pos += 1;
  }

  // 패턴을 끝까지 읽었다면
  if (pos == w.size()) {
    return pos == s.size(); // 문자열도 끝까지 읽었어야 매칭됨!
  }

  // 패턴이 아직 남았는데, 종료됨

  // '*'를 마주쳤다면?
  if (w[pos] == '*') {
    for(int skip = 0; pos + skip <= s.size(); skip++){
      if (match(w.substr(pos+1), s.substr(pos+skip))) {
        return true;
      }
    }
  }

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

    if (match(pattern, target)) {
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
