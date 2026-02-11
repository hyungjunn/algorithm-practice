// 백준 4179번: 불!
// https://www.acmicpc.net/problem/4179
#include <bits/stdc++.h>
using namespace std;

int R, C; // 1 <= R, C <= 1,000
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이 이동 시간
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
#define X first
#define Y second

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    fill(dist1[i], dist1[i] + C, -1);
    fill(dist2[i], dist2[i] + C, -1);
  }
  for (int i = 0; i < R; i++)
    cin >> board[i];
  queue<pair<int, int>> Q1; // 불
  queue<pair<int, int>> Q2; // 지훈이
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] == 'F') {
        Q1.emplace(i, j);
        dist1[i][j] = 0;
      }
      if (board[i][j] == 'J') {
        Q2.emplace(i, j);
        dist2[i][j] = 0;
      }
    }
  }
  while (!Q1.empty()) {
    auto cur = Q1.front(); Q1.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
      if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
      Q1.emplace(nx, ny);
    }
  }
  while (!Q2.empty()) {
    auto cur = Q2.front(); Q2.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
        cout << dist2[cur.X][cur.Y] + 1;
        return 0;
      }
      if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if (dist1[nx][ny] != -1 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;
      dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
      Q2.emplace(nx, ny);
    }
  }
  cout << "IMPOSSIBLE";
}