#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int R, C;
constexpr int MAX = 1005;
char board[MAX][MAX];
int dist_jihun[MAX][MAX];
int dist_fire[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    fill(dist_jihun[i], dist_jihun[i] + C, -1);
    fill(dist_fire[i], dist_fire[i] + C, -1);
  }

  queue<pair<int, int>> Q_fire;
  queue<pair<int, int>> Q_jihun;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'F') {
        Q_fire.emplace(i, j);
        dist_fire[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        Q_jihun.emplace(i, j);
        dist_jihun[i][j] = 0;
      }
    }
  }

  while (!Q_fire.empty()) {
    auto cur = Q_fire.front(); Q_fire.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
      if (dist_fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
      Q_fire.emplace(nx, ny);
    }
  }

  while (!Q_jihun.empty()) {
    auto cur = Q_jihun.front(); Q_jihun.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
        cout << dist_jihun[cur.X][cur.Y] + 1;
        return 0;
      }
      if (dist_jihun[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      // 불이 지나간 곳이고, 지훈이가 지나갔을 때 시간 >= 불이 지나간 시간 continue
      if (dist_fire[nx][ny] != -1 && dist_jihun[cur.X][cur.Y] + 1 >= dist_fire[nx][ny]) continue;
      dist_jihun[nx][ny] = dist_jihun[cur.X][cur.Y] + 1;
      Q_jihun.emplace(nx, ny);
    }
  }
  cout << "IMPOSSIBLE";
}