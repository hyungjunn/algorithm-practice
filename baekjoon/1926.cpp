// 백준 1926번: 그림
// https://www.acmicpc.net/problem/1926
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int board[502][502];
bool vis[502][502];
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  int num = 0;
  int mx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || board[i][j] == 0) continue;
      queue<pair<int, int>> Q;
      Q.emplace(i, j);
      num++;
      vis[i][j] = true;
      int area = 0;
      while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        area++;
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (board[nx][ny] == 0 || vis[nx][ny]) continue;
          Q.emplace(nx, ny);
          vis[nx][ny] = true;
        }
      }
      mx = max(mx, area);
    }
  }
  cout << num << '\n' << mx;
  return 0;
}