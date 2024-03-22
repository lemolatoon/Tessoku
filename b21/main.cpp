#include <bits/stdc++.h>
#include <cstdint>
#include <limits>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  string s;
  cin >> s;

  if (s.size() == 1) {
    cout << "1\n";
    return 0;
  }

  // dp[l][r]: the maximum kaibun length of S[l:r+1]
  vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0));

  for (const auto i : views::iota(0, n)) {
    // string of length == 1, is 1-length kaibun itself.
    dp[i][i] = 1;
  }

  for (const auto i : views::iota(0, n - 1)) {
    if (s[i] == s[i + 1]) {
      // if 2-length string has the same char, it is 2-length kaibun.
      dp[i][i + 1] = 2;
    } else {
      // otherwise, still 1-length kaibun (by removing one char)
      dp[i][i + 1] = 1;
    }
  }

  // loop over length, which means progressing dp with expanding length.
  for (const auto len : views::iota(2, n)) {
    for (const auto l : views::iota(0, n - len)) {
      const auto r = l + len;

      const auto min_v = numeric_limits<int64_t>::min() + 2;
      // Just non-relative char left or right, which doesnt affect kaibun length
      array<int64_t, 3> candidates = {dp[l + 1][r],dp[l][r - 1], min_v};

      if (s[l] == s[r]) {
        // When we have the same char at s[l], s[r], we can extend kaibun with that two chars.
        candidates[2] = dp[l + 1][r - 1] + 2;
      }

      dp[l][r] = ranges::max(candidates);
    }
  }

  cout << dp[0][n - 1] << endl;

  return 0;
}

