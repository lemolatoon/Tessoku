// delivery dp
#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  for (const auto i : views::iota(0, n - 1)) {
    cin >> a[i];
  }
  for (const auto i : views::iota(0, n - 2)) {
    cin >> b[i];
  }

  // dp[i]: the minimum time required for reaching room i.
  vector<int64_t> dp(n, numeric_limits<int64_t>::max() - 100);
  dp[0] = 0;

  for (const auto i : views::iota(0, n - 1)) {
    dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
    if (i + 2 < n) {
      dp[i + 2] = min(dp[i + 2], dp[i] + b[i]);
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}
