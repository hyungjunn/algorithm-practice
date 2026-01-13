#include <iostream>
#include <queue>
using namespace std;
constexpr int MAX = 505;
#define X first
#define Y second
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
int board[MAX][MAX];
bool visited[MAX][MAX];

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
      if (board[i][j] == 0 || visited[i][j]) continue;
      queue<pair<int, int> > Q;
      Q.emplace(i, j);
      visited[i][j] = true;
      pic_count++;
      int area = 1;
      while (!Q.empty()) {
        auto value = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
          int x = value.X + dx[dir];
          int y = value.Y + dy[dir];
          if (x < 0 || y < 0 || x >= n || y >= n) continue;
          if (board[x][y] == 0 || visited[x][y]) continue;
          Q.emplace(x, y);
          visited[x][y] = true;
          area++;
        }
      }
      max_area = max(max_area, area);
    }
  }
  cout << pic_count << '\n' << max_area;
  return 0;
}
