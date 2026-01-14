#include <iostream>
#include <queue>
using namespace std;
int n, m;
constexpr int MAX = 105;
int board[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
      char c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c;
      board[i][j] = c - '0';
    }
  }
  queue<pair<int, int>> Q;
  Q.emplace(1, 1);
  visited[1][1] = 1;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int x = cur.X + dx[dir];
      int y = cur.Y + dy[dir];
      if (x < 1 || y < 1 || x > n || y > m) continue;
      if (visited[x][y] || board[x][y] == 0) continue;
      Q.emplace(x, y);
      visited[x][y] = visited[cur.X][cur.Y] + 1;
      if (x == n && y == m) cout << visited[x][y];
    }
  }
}
