#include <bits/stdc++.h>
using namespace std;

int reverseNum(int num) {
  int reverseNum = 0;
  while (num > 0) {
    reverseNum = (reverseNum * 10) + (num % 10);
    num /= 10;
  }
  return reverseNum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B;
  cin >> A >> B;
  cout << max(reverseNum(A), reverseNum(B));
  return 0;
}
