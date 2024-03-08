#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, s;
  cin >> n >> s;

  vector<int64_t> a{};
  a.reserve(n);
  for (const auto _ : views::iota(0, n)) {
    int64_t tmp;
    cin >> tmp;
    a.emplace_back(tmp);
  }

  // dp[i][j]: is it possible to use card 0..i and make j by taking the sum.
  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
  dp[0][0] = true;

  for (const auto i : views::iota(1, n + 1)) {
    for (const auto j : views::iota(0, s + 1)) {
      if (dp[i - 1][j]) {
        // This is possible if you don't choose card i.
        dp[i][j] = true;
      }

      if (0 <= j - a[i - 1] && dp[i - 1][j - a[i - 1]]) {
        // This is possible if you choose card i.
        dp[i][j] = true;
      }
    }
  }

  if (dp[n][s]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
