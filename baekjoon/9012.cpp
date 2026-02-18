#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    stack<char> ps;
    for (const char ch : s) {
      if (ch == '(') {
        ps.push(ch);
      }
      else if (ch == ')') {
        if (ps.empty()) {
          ps.push(ch);
          break;
        }
        char t = ps.top();
        if (t == '(') {
          ps.pop();
        } else {
          ps.push(ch);
        }
      }
    }

    if (ps.empty()) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }

  }
}