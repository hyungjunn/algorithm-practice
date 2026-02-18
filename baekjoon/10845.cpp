#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  queue<int> q;

  while (N--) {
    string command;
    cin >> command;

    if (command == "push") {
      int n;
      cin >> n;
      q.push(n);
    } else if (command == "pop") {
      if (q.empty()) {
        cout << -1 << "\n";
        continue;
      }
      int f = q.front();
      q.pop();
      cout << f << "\n";
    } else if (command == "size") {
      cout << q.size() << "\n";
    } else if (command == "empty") {
      if (q.empty()) cout << 1 << "\n";
      else cout << 0 << "\n";
    } else if (command == "front") {
      if (q.empty()) cout << -1 << "\n";
      else cout << q.front() << "\n";
    } else {
      // back
      if (q.empty()) cout << -1 << "\n";
      else cout << q.back() << "\n";
    }
  }

}
