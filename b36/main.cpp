#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int64_t numOn = ranges::count_if(s, [](auto ch) { return ch == '1'; });

  if (numOn % 2 == k % 2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
