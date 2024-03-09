#include <array>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  std::string s;
  std::string t;
  cin >> s >> t;

  // dp[i][j]: the minimum levenshtein distance of s[:i], t[:j]
  vector<vector<int64_t>> dp(s.length() + 1,
                             vector<int64_t>(t.length() + 1, 0));

  for (const auto i : views::iota(static_cast<size_t>(1), s.length() + 1)) {
    dp[i][0] = i;
  }

  for (const auto j : views::iota(static_cast<size_t>(1), t.length() + 1)) {
    dp[0][j] = j;
  }

  for (const auto i : views::iota(static_cast<size_t>(1), s.length() + 1)) {
    for (const auto j : views::iota(static_cast<size_t>(1), t.length() + 1)) {
      array<int64_t, 3> candidates;
      candidates[0] = dp[i - 1][j] + 1;
      candidates[1] = dp[i][j - 1] + 1;

      // NOTE: s, t is 0-origin, dp is 1-origin
      if (s[i - 1] == t[j - 1]) {
        // If next char of s, t is the same, you don't need edit.
        candidates[2] = dp[i - 1][j - 1];
      } else {
        // If not the same, need to substitute.
        candidates[2] = dp[i - 1][j - 1] + 1;
      }

      dp[i][j] = ranges::min(candidates);
    }
  }

  cout << dp[s.length()][t.length()] << endl;
  return 0;
}
