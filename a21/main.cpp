#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> p, a;

  for (const auto _ : views::iota(0, n)) {
    int64_t tmp_p, tmp_a;
    cin >> tmp_p >> tmp_a;

    p.emplace_back(tmp_p);
    a.emplace_back(tmp_a);
  }

  // dp[i][j]: the maximum score when i..=j blocks are remained.
  vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0));

  // When all blocks are remained, the score is zero.
  dp[0][n - 1] = 0;

  for (const auto i : views::iota(0, n)) {
    for (const auto j : views::iota(0, n) | views::reverse) {
      if (i == 0 && j == n - 1)
        continue;

      constexpr auto minusInf = numeric_limits<int64_t>::min();
      array<int64_t, 2> candidates = {minusInf, minusInf};

      // remove i - 1 block from i - 1..=j
      if (i - 1 >= 0 && i <= p[i - 1] - 1 && p[i - 1] - 1 <= j) {
        candidates[0] = dp[i - 1][j] + a[i - 1];
      } else if (i - 1 >= 0) {
        candidates[0] = dp[i - 1][j];
      }

      // remove j + 1 block from i..=j + 1
      if (j + 1 < n && i <= p[j + 1] - 1 && p[j + 1] - 1 <= j) {
        candidates[1] = dp[i][j + 1] + a[j + 1];
      } else if (j + 1 < n) {
        candidates[1] = dp[i][j + 1];
      }

      dp[i][j] = ranges::max(candidates);
    }
  }

  auto max_score =
      ranges::max(views::iota(static_cast<size_t>(0), dp.size()) |
                  views::transform([&](auto i) { return dp[i][i]; }));

  cout << max_score << endl;
  return 0;
}
