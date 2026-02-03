// 백준 1697번: 숨바꼭질
// https://www.acmicpc.net/problem/1697
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, K;
int times[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;
  fill(times, times + 100004, -1);
  times[N] = 0;
  queue<int> Q;
  Q.emplace(N);
  while (times[K] == -1) {
    auto cur = Q.front(); Q.pop();
    for (int nxt : {cur-1, cur+1, cur*2}) {
      if (nxt < 0 || nxt > 100000) continue;
      if (times[nxt] != -1) continue;
      times[nxt] = times[cur] + 1;
      Q.emplace(nxt);
    }
  }
  cout << times[K];
}