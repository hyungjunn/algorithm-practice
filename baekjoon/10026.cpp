// 백준 10026번: 적록색약
// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;
int N;
char board[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[105][105];

void bfs(int i, int j) {
  queue<pair<int, int>> Q;
  Q.emplace(i, j);
  visited[i][j] = true;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if (board[cur.X][cur.Y] != board[nx][ny] || visited[nx][ny]) continue;
      visited[nx][ny] = true;
      Q.emplace(nx, ny);
    }
  }
}

int get_count() {
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j]) continue;
      bfs(i, j);
      count++;
    }
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> board[i][j];

  int count1 = get_count();

  // 초기화
  for (int i = 0; i < N; i++) {
    fill(visited[i], visited[i] + N, false);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 'G') {
        board[i][j] = 'R';
      }
    }
  }

  int count2 = get_count();

  cout << count1 << ' ' << count2;
}