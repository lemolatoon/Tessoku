#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  std::string s, t;
  cin >> s >> t;

  // dp[i][j]: maximum length of common substring between s[:i+1] and t[:j+1]
  vector<vector<int64_t>> dp(s.length() + 1,
                             vector<int64_t>(t.length() + 1, 0));

  for (const auto i : views::iota(1, static_cast<int64_t>(s.length() + 1))) {
    for (const auto j : views::iota(0, static_cast<int64_t>(t.length() + 1))) {
      array<int64_t, 3> candidate{std::numeric_limits<int64_t>::min(),
                                  std::numeric_limits<int64_t>::min(),
                                  std::numeric_limits<int64_t>::min()};
      // If s[i - 1] == t[j - 1] (NOTE: s, t is 0-origin, dp is 1-origin), you
      // can increment length of common substring.
      // If not, just use maximum of previous value
      // (without s[i - 1] or t[j - 1] value)
      candidate[0] = dp[i - 1][j];
      if (0 <= j - 1) {
        candidate[1] = dp[i][j - 1];
      }
      if (0 <= j - 1 && s[i - 1] == t[j - 1]) {
        candidate[2] = dp[i - 1][j - 1] + 1;
      }

      dp[i][j] = ranges::max(candidate);
    }
  }

  cout << dp[s.length()][t.length()] << endl;
  return 0;
}
