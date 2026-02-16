#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int R;
    cin >> R;
    string s;
    cin >> s;
    for (const auto &ch : s) {
      for (int i = 0; i < R; i++) cout << ch;
    }
    cout << '\n';
  }
}
