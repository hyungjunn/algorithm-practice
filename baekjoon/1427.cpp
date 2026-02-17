#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string num_str;
  std::cin >> num_str;

  std::sort(num_str.rbegin(), num_str.rend());

  std::cout << num_str << '\n';
  return 0;
}