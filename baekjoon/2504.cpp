#include <string>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  stack<char> st;
  int temp = 1; // 배율관련한 변수
  int result = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '(') {
      temp *= 2;
      st.push(s[i]);
    } else if (s[i] == '[') {
      temp *= 3;
      st.push(s[i]);
    } else if (s[i] == ')') {
      if (st.empty()) {
        cout << 0;
        return 0;
      }
      char c = st.top();
      if (c != '(') {
        cout << 0;
        return 0;
      }
      if (s[i - 1] == '(') {
        result += temp;
      }
      st.pop();
      temp /= 2;
    } else {
      if (st.empty()) {
        cout << 0;
        return 0;
      }
      char c = st.top();
      if (c != '[') {
        cout << 0;
        return 0;
      }
      if (s[i - 1] == '[') {
        result += temp;
      }
      st.pop();
      temp /= 3;
    }
  }
  if (!st.empty()) {
    cout << 0;
    return 0;
  }
  cout << result;
  return 0;
}
