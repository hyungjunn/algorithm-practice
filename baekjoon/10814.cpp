#include <bits/stdc++.h>
using namespace std;

vector<string> age_buckets[201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  if (!(cin >> N)) return 0;

  int age;
  string name;
  for (int i = 0; i < N; i++) {
    cin >> age >> name;
    age_buckets[age].push_back(name);
  }

  for (int i = 1; i <= 200; i++) {
    for (const string& s : age_buckets[i]) {
      cout << i << ' ' << s << '\n';
    }
  }

  return 0;
}