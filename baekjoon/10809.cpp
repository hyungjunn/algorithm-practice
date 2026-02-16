#include <bits/stdc++.h>
using namespace std;
int alpha[26]; // 알파벳이 처음 등장하는 인덱스
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  for (int i = 0; i < 26; i++) alpha[i] = -1;
  for (int i = 0; i < S.length(); i++) {
    // i에 해당하는 문자 - 'a'의 alpha에 i를 할당. 단, -1이 아닌 경우 continue;
    if (alpha[S[i] - 'a'] != -1) continue;
    alpha[S[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; i++) {
    cout << alpha[i] << ' ';
  }
  return 0;
}
