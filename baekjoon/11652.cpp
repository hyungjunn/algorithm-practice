// 백준 11652번: 카드
// https://www.acmicpc.net/problem/11652
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<long long> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  long long ans = v[0];
  int max_count = 1;
  int cur_count = 1;

  for (int i = 1; i < N; i++) {
    if (v[i] == v[i - 1]) {
      cur_count++;
    } else {
      cur_count = 1;
    }
    if (cur_count > max_count) {
      max_count = cur_count;
      ans = v[i];
    }
  }

  cout << ans;

  return 0;
}