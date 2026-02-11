// 백준 15683번: 감시
// https://www.acmicpc.net/problem/15683
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;

bool OOB(int a, int b) {
  return a < 0 || b < 0 || a >= n || b >= m;
}

void upd(int x, int y, int dir) {
  dir %= 4;
  while (1) {
    x = x + dx[dir];
    y = y + dy[dir];
    if (OOB(x, y) || board2[x][y] == 6) return;
    if (board2[x][y] != 0) continue;
    board2[x][y] = 7;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  int mn = 0; // 사각지대 최소 크기
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board1[i][j];
      if (board1[i][j] != 0 && board1[i][j] != 6) {
        cctv.emplace_back(i, j);
      }
      if (board1[i][j] == 0) mn++;
    }
  }
  for (int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        board2[i][j] = board1[i][j];
    int brute = tmp;
    for (int i = 0; i < cctv.size(); i++) {
      int dir = brute % 4;
      brute /= 4;
      int x = cctv[i].X;
      int y = cctv[i].Y;
      if (board1[x][y] == 1) {
        upd(x, y, dir);
      }
      else if (board1[x][y] == 2) {
        upd(x, y, dir);
        upd(x, y, dir + 2);
      }
      else if (board1[x][y] == 3) {
        upd(x, y, dir);
        upd(x, y, dir + 1);
      }
      else if (board1[x][y] == 4) {
        upd(x, y, dir);
        upd(x, y, dir + 1);
        upd(x, y, dir + 2);
      }
      else { // (board1[x][y] == 5)
        upd(x, y, dir);
        upd(x, y, dir + 1);
        upd(x, y, dir + 2);
        upd(x, y, dir + 3);
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board2[i][j] == 0) count++;
      }
    }
    mn = min(mn, count);
  }
  cout << mn;
}
