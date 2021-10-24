#include <bits/stdc++.h>

#define MAX 30

using namespace std;

vector<int> converStringToInt(string &str) {
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

// 긴 정수 덧셈 a += b * (10^k)
void addTo(vector<int> &a, const vector<int> &b, int k) {
  for (int i = 0; i < b.size() + k; i++) {
    a.push_back(0);
  }
  for (int i = k; i < a.size(); i++) {
    a[i] += b[i - k];
  }
  normalize(a);
}

// 긴 정수 뺄셈: a -= b
void subFrom(vector<int> &a, const vector<int> &b) {
  for (int i = 0; i < b.size(); i++) {
    a[i] -= b[i];
  }
  normalize(a);
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
  int an = a.size(), bn = b.size();
  if (an < bn) return karatsuba(b, a); // a가 b보다 짧다면 둘을 교환 (순서 강제)

  if (an == 0 || bn == 0) return vector<int>(); // a 또는 b가 비어있다면 빈 배열을 리턴

  if (an <= 50) return multiply(a, b); // a가 비교적 짧다면 O(n^2)의 알고리즘으로 계산

  int half = an / 2;

  vector<int> a0(a.begin(), a.begin() + half);
  vector<int> a1(a.begin() + half, a.end());
  vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
  vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

  vector<int> z0 = karatsuba(a0, b0);
  vector<int> z2 = karatsuba(a1, b1);

  addTo(a0, a1, 0);
  addTo(b0, b1, 0);
  vector<int> z1 = karatsuba(a0, b0);

  subFrom(z1, z0);
  subFrom(z1, z2);

  vector<int> ret;
  addTo(ret, z0, 0);
  addTo(ret, z1, half);
  addTo(ret, z2, half + half);

  return ret;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  vector<int> n1 = converStringToInt(s1);
  vector<int> n2 = converStringToInt(s2);

  vector<int> ret = karatsuba(n1, n2);

  for (int i = ret.size() - 1; i >= 0; i--) {
    printf("%d", ret[i]);
  }

}