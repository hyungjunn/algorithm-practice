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
  fill(times, times+100004, -1); // TODO: 범위 조심
  times[N] = 0;
  queue<int> Q;
  Q.push(N);
  while (times[K] == -1) {
    auto cur = Q.front(); Q.pop();
    for (int next : {cur-1, cur+1, cur*2}) { // TODO: 아이디어
      if (next < 0 || next > 100000) continue;
      if (times[next] != -1) continue;
      times[next] = times[cur] + 1;
      Q.push(next);
    }
  }
  cout << times[K];
}