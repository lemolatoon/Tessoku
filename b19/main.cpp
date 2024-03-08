#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n, w_max;
  cin >> n >> w_max;
  vector<int64_t> w, v;
  w.reserve(n);
  v.reserve(n);

  for (const auto _ : views::iota(0, n)) {
    int64_t t_w, t_v;
    cin >> t_w >> t_v;

    w.emplace_back(t_w);
    v.emplace_back(t_v);
  }

  const int64_t v_max = 1000 * 100;

  // dp[i][j]: minimum sum of weights of treasures
  // , where use exactly value j, and treasures 1..i
  vector<vector<int64_t>> dp(
      n + 1, vector<int64_t>(v_max + 1, numeric_limits<int64_t>::max() / 2));

  // minimum sum of weights are 0, where 0 value and 0 treasures.
  dp[0][0] = 0;

  for (const auto i : views::iota(1, n + 1)) {
    for (const auto j : views::iota(0, v_max + 1)) {
      // If treasure i is selectable.
      if (0 <= j - v[i - 1]) {
        // take the minimum value, putting treasure i or not.
        dp[i][j] = min(dp[i - 1][j - v[i - 1]] + w[i - 1], dp[i - 1][j]);
      } else {
        // Just not putting treasure i.
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // auto max_value = ranges::max(
  //     views::enumerate(dp[n]) |
  //     views::filter([&](auto [_, weight]) { return weight <= w_max; }));
  int64_t max_value = 0;
  for (const auto j : views::iota(0, v_max + 1)) {
    if (dp[n][j] > w_max) {
      continue;
    }
    max_value = max(max_value, static_cast<int64_t>(j));
  }

  cout << max_value << endl;
  return 0;
}
