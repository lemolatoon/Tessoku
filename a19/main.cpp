#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, w_max;
  cin >> n >> w_max;
  vector<int64_t> w, v;
  w.reserve(n);
  v.reserve(n);

  for (const auto _ : views::iota(0, n)) {
    int64_t tmp_w, tmp_v;
    cin >> tmp_w >> tmp_v;
    w.emplace_back(tmp_w);
    v.emplace_back(tmp_v);
  }

  // dp[i][j]: max value of sum, when using treasure [1, i] and sum of their
  // weights are j.
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(w_max + 1, -1));

  // max value of 'no treasure with 0 weight' is 0.
  dp[0][0] = 0;

  for (const auto i : views::iota(1, n + 1)) {
    for (const auto j : views::iota(0, w_max + 1)) {
      // if treasure i can be put in the bag.
      if (0 <= j - w[i - 1]) {
        // Choose the value-larger option, putting treasure i or not.
        dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
      } else {
        // Not putting treasure i because you don't have enough bag capacity.
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  auto max_value = max_element(dp[n].begin(), dp[n].end());

  cout << *max_value << endl;

  return 0;
}
