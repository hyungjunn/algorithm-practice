// 백준 7795번: 먹을 것인가 먹힐 것인가
// https://www.acmicpc.net/problem/7795
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
      cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long count = 0;
    for (int i = 0; i < N; i++) {
      auto lower = lower_bound(B.begin(), B.end(), A[i]);
      count += (lower - B.begin());
    }

    cout << count << '\n';
  }

  return 0;
}