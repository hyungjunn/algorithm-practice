#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool is_used[10];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  // 0번째 들어갈 수를 정해야돼. 1부터 n까지
  for (int i = 1; i <= n; i++) {
    if (is_used[i]) continue;
    arr[k] = i;
    is_used[i] = true;
    func(k + 1);
    is_used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  func(0);
}