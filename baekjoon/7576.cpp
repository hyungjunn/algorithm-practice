// 백준 7576번: 토마토
// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <queue>
#include <algorithm>
int n, m;
int board[1002][1002];
int dist[1002][1002];
#define X first
#define Y second
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        Q.emplace(i, j);
      }
      if (board[i][j] == 0) {
        dist[i][j] = -1;
      }
    }
  }
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (dist[nx][ny] >= 0) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.emplace(nx, ny);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == -1) {
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans;
  return 0;
}
