// 백준 15683번: 감시
// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int> > cctv_list;
int min_ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void check(int y, int x, int dir, vector<vector<int> > &map) {
  int ny = y;
  int nx = x;
  while (true) {
    ny += dy[dir];
    nx += dx[dir];
    if (nx < 0 || ny < 0 || nx >= m || ny >= n) break;
    if (map[ny][nx] == 6) break;
    if (map[ny][nx] == 0) {
      map[ny][nx] = 7;
    }
  }
}

void dfs(int idx, vector<vector<int> > current_map) {
  if (idx == cctv_list.size()) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (current_map[i][j] == 0) {
          count += 1;
        }
      }
    }
    min_ans = min(min_ans, count);
    return;
  }
  int y = cctv_list[idx][0];
  int x = cctv_list[idx][1];
  int type = cctv_list[idx][2];
  if (type == 1) {
    for (int dir = 0; dir < 4; dir++) {
      vector<vector<int> > next_map = current_map;
      check(y, x, dir, next_map);
      dfs(idx + 1, next_map);
    }
  } else if (type == 2) {
    for (int dir = 0; dir < 2; dir++) {
      vector<vector<int> > next_map = current_map;
      check(y, x, dir, next_map);
      check(y, x, dir + 2, next_map);
      dfs(idx + 1, next_map);
    }
  } else if (type == 3) {
    for (int dir = 0; dir < 4; dir++) {
      vector<vector<int> > next_map = current_map;
      check(y, x, dir, next_map);
      check(y, x, (dir + 1) % 4, next_map);
      dfs(idx + 1, next_map);
    }
  } else if (type == 4) {
    for (int dir = 0; dir < 4; dir++) {
      vector<vector<int> > next_map = current_map;
      check(y, x, dir, next_map);
      check(y, x, (dir + 1) % 4, next_map);
      check(y, x, (dir + 2) % 4, next_map);
      dfs(idx + 1, next_map);
    }
  } else if (type == 5) {
    vector<vector<int> > next_map = current_map;
    check(y, x, 0, next_map);
    check(y, x, 1, next_map);
    check(y, x, 2, next_map);
    check(y, x, 3, next_map);
    dfs(idx + 1, next_map);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  min_ans = n * m;
  vector<vector<int> > start_map(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> start_map[i][j];
      if (start_map[i][j] == 0 || start_map[i][j] == 6) continue;
      cctv_list.push_back({i, j, start_map[i][j]});
    }
  }
  dfs(0, start_map);
  cout << min_ans;
  return 0;
}
