// 백준 1926번: 그림
// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>
using namespace std;
int n, m; // 1 <= n, m <= 500
int board[502][502];
bool vis[502][502];
#define X first
#define Y second
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  int num = 0;
  int max_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || board[i][j] == 0) continue;
      num++;
      queue<pair<int, int> > Q;
      Q.emplace(i, j);
      vis[i][j] = true;
      int area = 0;
      while (!Q.empty()) {
        auto cur = Q.front();
        area++;
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = true;
          Q.emplace(nx, ny);
        }
      }
      max_area = max(max_area, area);
    }
  }
  cout << num << '\n' << max_area;
  return 0;
}