// 백준 7576번: 토마토
// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <queue>
using namespace std;
int M, N;
constexpr int MAX = 1000;
int board[MAX][MAX];
bool visited[MAX][MAX];
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int level[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> M >> N; // M:가로, N:세로
  for (int j = 0; j < N; j++)
    for (int i = 0; i < M; i++)
      cin >> board[i][j];
  queue<pair<int, int> > Q;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (visited[i][j] || board[i][j] != 1) continue;
      Q.emplace(i, j);
      visited[i][j] = true;
      level[i][j] = 0;
    }
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int x = cur.X + dx[dir];
      int y = cur.Y + dy[dir];
      if (x < 0 || y < 0 || x >= M || y >= N) continue;
      if (visited[x][y] || board[x][y] == -1) continue;
      Q.emplace(x, y);
      board[x][y] = 1;
      visited[x][y] = true;
      level[x][y] = level[cur.X][cur.Y] + 1;
    }
  }
  int max_days = 0;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (board[i][j] == 0) {
        cout << -1;
        return 0;
      }
      max_days = max(max_days, level[i][j]);
    }
  }
  cout << max_days;
}
