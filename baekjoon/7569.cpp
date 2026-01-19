#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H;
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
int board[101][101][101];
queue<tuple<int, int, int> > Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> M >> N >> H;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        int tmp;
        cin >> tmp;
        board[j][k][i] = tmp;
        if (tmp == 1) Q.emplace(j, k, i);
        if (tmp == -1) board[j][k][i] = -1;
      }
    }
  }

  while (!Q.empty()) {
    auto [curX, curY, curZ] = Q.front();
    Q.pop();
    for (int dir = 0; dir < 6; dir++) {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
      if (board[nx][ny][nz] != 0) continue;
      board[nx][ny][nz] = board[curX][curY][curZ] + 1;
      Q.emplace(nx, ny, nz);
    }
  }

  int result = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (board[j][k][i] == 0) {
          cout << -1 << '\n';
          return 0;
        }
        result = max(result, board[j][k][i]);
      }
    }
  }
  cout << result - 1;
  return 0;
}
