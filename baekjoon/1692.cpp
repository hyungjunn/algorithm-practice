#include <iostream>
using namespace std;
using ll = long long;

ll func1(int a, int b, int m) {
  int val = 1;
  while (b--) val = val * a % m; // O(b)인데, 만약 b가 2억을 넘으면? 시간초과.
  return val;
}

ll POW(ll a, ll b, ll m) {
  if (b == 1) return a % m;
  ll val = POW(a, b/2, m);
  val = val * val % m;
  if (b % 2 == 0) return val;
  return val * a % m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c;
  cin >> a >> b >> c;
  cout << POW(a, b, c);
}