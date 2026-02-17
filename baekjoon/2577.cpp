#include <bits/stdc++.h>
using namespace std;
int no[10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B, C;
  cin >> A >> B >> C;
  int D = A * B * C;
  while (D > 0) {
    no[D % 10]++;
    D /= 10;
  }
  for (int i = 0; i < 10; i++) {
    cout << no[i] << '\n';
  }
}