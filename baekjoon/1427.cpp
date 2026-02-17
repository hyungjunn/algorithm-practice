#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int num;
  cin >> num;
  vector<int> v;
  while (num > 0) {
    v.push_back(num % 10);
    num /= 10;
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0 ; i--) {
    cout << v[i];
  }
}