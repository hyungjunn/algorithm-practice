#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> q1;
    priority_queue<int> q2; // 중요도 나열

    for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      q1.emplace(i, num);
      q2.emplace(num);
    }

    int cnt = 0;
    while (!q1.empty()) {
      auto cur = q1.front();
      q1.pop();
      if (cur.second < q2.top()) {
        q1.emplace(cur);
      } else {
        // 프린트를 하는데 그건 여기서 중요하지 않음.
        q2.pop();
        cnt++;
        if (cur.first == M) {
          cout << cnt << "\n";
          break;
        }
      }
    }
  }

  return 0;
}
