#include <bits/stdc++.h>
using namespace std;
vector<int> findAlphabetIndices(const string & s) {
  vector<int> alpha(26, -1);
  for (size_t i = 0; i < s.length(); ++i) {
    int charIdx = s[i] - 'a';
    if (alpha[charIdx] == -1) {
      alpha[charIdx] = static_cast<int>(i);
    }
  }
  return alpha;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  if (cin >> S) {
    vector<int> result = findAlphabetIndices(S);
    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << '\n';
  }
  return 0;
}
