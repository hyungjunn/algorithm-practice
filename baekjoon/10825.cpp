#include <bits/stdc++.h>

using namespace std;

struct Student {
  string name;
  int ko, en, math;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  if (!(cin >> N)) return 0;

  vector<Student> v;
  v.reserve(N);
  for (int i = 0; i < N; i++) {
    Student s;
    cin >> s.name >> s.ko >> s.en >> s.math;
    v.push_back(s);
  }

  sort(v.begin(), v.end(), [](const Student &a, const Student &b) {
    if (a.ko != b.ko) return a.ko > b.ko;
    if (a.en != b.en) return a.en < b.en;
    if (a.math != b.math) return a.math > b.math;
    return a.name < b.name;
  });

  for (auto &stu : v) {
    cout << stu.name << "\n";
  }
}
