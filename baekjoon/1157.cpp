#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int cnt[26] = {};
  for (unsigned char ch : s) {
    ch = toupper(ch);
    cnt[ch - 'A']++;
  }
  int best = -1, idx = -1;
  bool tie = false;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > best) {
      best = cnt[i];
      idx = i;
      tie = false;
    } else if (cnt[i] == best) {
      tie = true;
    }
  }
  cout << (tie ? '?' : static_cast<char>('A' + idx));
}