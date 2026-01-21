#include <iostream>
using namespace std;
int T, n;
constexpr int MAX = 100005;
int stu[MAX];
bool visited[MAX];
bool finished[MAX];
int cnt = 0;

void dfs(int x) {
  visited[x] = true;
  int next = stu[x];
  if (!visited[next]) {
    dfs(next);
  } else { // 방문을 했던 곳이라면
    if (!finished[next]) { // 진행 중인 노드일 때
      // next에서 출발해서 stu[]를 계속 따라가면 다시 next로 돌아온다
      int temp = next;
      while (temp != x) {
        temp = stu[temp];
        cnt++;
      }
      cnt++;
    }
  }
  finished[x] = true;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> stu[i];
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i]) continue;
      dfs(i);
    }
    cout << (n - cnt) << '\n';
    for (int i = 1; i <= n; i++) {
      visited[i] = false;
      finished[i] = false;
    }
    cnt = 0;
  }
}