// 백준 2178번: 미로 탐색
// https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
using namespace std;
int n, m; // 2 <= n, m <= 100
char board[102][102];
bool vis[102][102];
#define X first
#define Y second
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dist[102][102];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> board[i][j];
  queue<pair<int, int>> Q;
  Q.emplace(1, 1);
  vis[1][1] = true;
  dist[1][1] = 1;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if (vis[nx][ny] || board[nx][ny] == '0') continue;
      vis[nx][ny] = true;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      Q.emplace(nx, ny);
    }
  }
  cout << dist[n][m];
  return 0;
}
