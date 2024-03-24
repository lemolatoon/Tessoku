#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n - 1), b(n - 1);
  for (const auto i : views::iota(0, n - 1)) {
    cin >> a[i];
    a[i]--;
  }
  for (const auto i : views::iota(0, n - 1)) {
    cin >> b[i];
    b[i]--;
  }

  // dp[i]: maximum score until reaching i'th spot.
  vector<int64_t> dp(n, numeric_limits<int64_t>::min());
  dp[0] = 0;
  for (const auto i : views::iota(0, n - 1)) {
    dp[a[i]] = max(dp[a[i]], dp[i] + 100);
    dp[b[i]] = max(dp[b[i]], dp[i] + 150);
  }

  cout << dp[n - 1] << endl;
  return 0;
}
