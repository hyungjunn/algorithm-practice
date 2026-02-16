#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  getline(cin, s);
  stringstream ss(s);
  string word;
  int count = 0;
  while (ss >> word) count++;
  cout << count;
  return 0;
}
