#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T, R;
  string s;
  cin >> T;
  while (T--) {
    cin >> R >> s;
    for (const auto ch : s) {
      for (int i = 0; i < R; i++) cout << ch;
    }
    cout << '\n';
  }
}
