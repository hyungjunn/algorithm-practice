#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B;
  cin >> A >> B;
  int C = 0, D = 0;
  int C_length = 10 * 10;
  for (int i = 0; i < 3; i++) {
    C += (A % 10) * C_length;
    A /= 10;
    C_length /= 10;
  }
  int D_length = 10 * 10;
  for (int i = 0; i < 3; i++) {
    D += (B % 10) * D_length;
    B /= 10;
    D_length /= 10;
  }
  if (C >= D) {
    cout << C;
  } else {
    cout << D;
  }
  return 0;
}