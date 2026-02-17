#include <bits/stdc++.h>
using namespace std;
int no[1002];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  while (N--) {
    int num;
    cin >> num;
    no[num]++;
  }
  for (int i = 1; i <= 1000; i++) {
    if (no[i] == 0) continue;
    cout << i << '\n';
  }
}
