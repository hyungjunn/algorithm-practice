// 백준 4179번: 불!
// https://www.acmicpc.net/problem/4179
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int R, C; // 1<=R,C<=1000
constexpr int MAX = 1005;
char board[MAX][MAX];
int dist_fire[MAX][MAX];
int dist_jihun[MAX][MAX];
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    fill(dist_fire[i], dist_fire[i] + C, -1);
    fill(dist_jihun[i], dist_jihun[i] + C, -1);
  }

  // 불이 처음 존재하는 곳은 시간을 0으로 설정하고 Q에 넣는다.
  queue<pair<int, int>> Q_fire;
  queue<pair<int, int>> Q_jihun;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'F') {
        dist_fire[i][j] = 0;
        Q_fire.emplace(i, j);
      }
      if (board[i][j] == 'J') {
        dist_jihun[i][j] = 0;
        Q_jihun.emplace(i, j);
      }
    }
  }

  // 불 BFS
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

  // 지훈이 BFS
  while (!Q_jihun.empty()) {
    auto cur = Q_jihun.front(); Q_jihun.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
        cout << (dist_jihun[cur.X][cur.Y] + 1);
        return 0;
      }
      if (dist_jihun[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if (dist_fire[nx][ny] == -1 || dist_jihun[cur.X][cur.Y] + 1 < dist_fire[nx][ny]) {
        dist_jihun[nx][ny] = dist_jihun[cur.X][cur.Y] + 1;
        Q_jihun.emplace(nx, ny);
      }
    }
  }
  cout << "IMPOSSIBLE";
}