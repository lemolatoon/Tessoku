#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n, m;
  cin >> n >> m;
  vector<vector<int64_t>> a(m, vector<int64_t>(n));

  for (const auto i : views::iota(0, m)) {
    for (const auto j : views::iota(0, n)) {
      cin >> a[i][j];
    }
  }

  // dp[i][S]: the minimum coupon[0..i] usage with exact free buyable products
  // set S.
  vector<vector<int64_t>> dp(m + 1, vector<int64_t>(1 << n, -1));
  dp[0][0] = 0;

  for (const auto i : views::iota(0, m)) {
    for (const auto s : views::iota(0, 1 << n)) {
      if (dp[i][s] == -1) {
        continue;
      }
      // construct coupon (i + 1)'s buyable set.
      int64_t t = 0;
      for (const auto k : views::iota(0, n)) {
        if (a[i][k] == 1) {
          t |= (1 << k);
        }
      }
      // use coupon i + 1
      auto &prev_val = dp[i + 1][s | t];
      auto updating = dp[i][s] + 1;
      if (prev_val == -1) {
        prev_val = updating;
      } else {
        prev_val = min(prev_val, updating);
      }

      // not use coupon i + 1
      auto &prev_val2 = dp[i + 1][s];
      auto updating2 = dp[i][s];
      if (prev_val2 == -1) {
        prev_val2 = updating2;
      } else {
        prev_val2 = min(prev_val2, updating2);
      }
    }
  }

  cout << dp[m][(1 << n) - 1] << endl;
  return 0;
}
