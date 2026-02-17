#include <bits/stdc++.h>
using namespace std;
int num[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
  }
  sort(num, num + N);
  for (int i = 0; i < N; i++) cout << num[i] << '\n';
}
