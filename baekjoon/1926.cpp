// 백준 1926번: 그림
// https://www.acmicpc.net/problem/1926
#include <iostream>
#include <queue>
using namespace std;
int n, m;
constexpr int MAX = 505;
int board[MAX][MAX];
bool visited[MAX][MAX];
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
  int pic_count = 0;
  int max_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] || board[i][j] == 0) continue;
      // 방문을 하지 않았고 1인경우
      queue<pair<int, int>> Q;
      Q.emplace(i, j);
      pic_count++;
      visited[i][j] = true;
      int area = 1;
      while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (visited[nx][ny] || board[nx][ny] == 0) continue;
          Q.emplace(nx, ny);
          visited[nx][ny] = true;
          area++;
        }
      }
      max_area = max(max_area, area);
    }
  }
  cout << pic_count << '\n' << max_area;
}