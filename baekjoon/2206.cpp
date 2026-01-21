// 백준 2206번: 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
char board[1005][1005];
int dist[1005][1005][2];

int bfs() {
  queue<tuple<int, int, int> > Q;
  Q.emplace(0, 0, 0);
  dist[0][0][0] = 1;
  while (!Q.empty()) {
    auto [curX, curY, curZ] = Q.front();
    Q.pop();
    if (curX == N - 1 && curY == M - 1) return dist[curX][curY][curZ];
    for (int dir = 0; dir < 4; ++dir) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if (board[nx][ny] == '0' && dist[nx][ny][curZ] == -1) {
        dist[nx][ny][curZ] = dist[curX][curY][curZ] + 1;
        Q.emplace(nx, ny, curZ);
      } else if (board[nx][ny] == '1' && curZ == 0 && dist[nx][ny][1] == -1) {
        dist[nx][ny][1] = dist[curX][curY][curZ] + 1;
        Q.emplace(nx, ny, 1);
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      dist[i][j][0] = dist[i][j][1] = -1;
    }
  }
  cout << bfs();

  return 0;
}
