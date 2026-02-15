#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  map<char, int> mp;
  for (char c : s) {
    if ('A' <= c && c <= 'Z') {
      c += 32;
    }
    if (mp.find(c) != mp.end()) {
      mp[c] += 1;
    } else {
      mp.insert({c, 1});
    }
  }
  int maxValue = -1;
  char maxKey = '?';
  bool is_question = false;
  for (auto &p : mp) {
    if (p.second > maxValue) {
      maxValue = p.second;
      maxKey = p.first;
      is_question = false;
    }
    else if (p.second == maxValue) {
      is_question = true;
    }
  }
  if (is_question) {
    cout << '?';
  } else {
    cout << char(maxKey - 32);
  }

}