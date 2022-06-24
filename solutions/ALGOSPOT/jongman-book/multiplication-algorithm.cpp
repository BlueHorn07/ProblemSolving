#include <bits/stdc++.h>

#define MAX 30

using namespace std;

vector<int> convertStringToInt(string &str) {
  vector<int> number;
  for (int i = str.size() - 1; i >= 0; i--) {
    number.push_back(int(str[i]) - '0');
  }
  return number;
}

void normalize(vector<int> &n) {
  n.push_back(0);
  for (int i = 0; i + 1 < n.size(); i++) {
    if (n[i] >= 0) {
      n[i + 1] += n[i] / 10;
      n[i] = n[i] % 10;
    } else {
      int borrow = (abs(n[i]) + 9) / 10;
      n[i + 1] -= borrow;
      n[i] += borrow * 10;
    }
  }
  while (n.size() > 1 && n.back() == 0) n.pop_back();
}

vector<int> multiply(const vector<int> &n1, const vector<int> &n2) {
  vector<int> ret(n1.size() + n2.size() + 1);
  for (int i = 0; i < n1.size(); i++) {
    for (int j = 0; j < n2.size(); j++) {
      ret[i + j] += n1[i] * n2[j];
    }
  }
  normalize(ret);
  return ret;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  vector<int> n1 = convertStringToInt(s1);
  vector<int> n2 = convertStringToInt(s2);

  vector<int> ret = multiply(n1, n2);

  for (int i = ret.size() - 1; i >= 0; i--) {
    printf("%d", ret[i]);
  }

  return 0;
}