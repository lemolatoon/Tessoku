#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;
  bool reachability = (k >= 2 * n - 2) && (k % 2 == 0);
  if (reachability) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
