#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<array<int64_t, 2>> positions(n);

  for (const auto i : views::iota(0, n)) {
    cin >> positions[i][0]; // x
    cin >> positions[i][1]; // y
  }

  double min_time = numeric_limits<double>::max() / 2;
  for (const auto start_position : views::iota(0, n)) {
    // dp[S][i]: the minimum travel time,
    // where set S: already traveled cities
    //  position i: current position [x, y] == positions[i]
    vector<vector<double>> dp(
        1 << n, vector<double>(n, numeric_limits<double>::max() / 2));

    dp[0][start_position] = 0;
    for (const auto s : views::iota(0, 1 << n)) {
      for (const auto i : views::iota(0, n)) {
        auto &updating = dp[s | (1 << i)][i];
        for (const auto j : views::iota(0, n)) {
          auto xdiff = positions[i][0] - positions[j][0];
          xdiff = xdiff * xdiff;
          auto ydiff = positions[i][1] - positions[j][1];
          ydiff = ydiff * ydiff;
          auto diff = xdiff + ydiff;

          updating = min(updating, dp[s][j] + sqrt(diff));
        }
      }
    }

    for (const auto i : views::iota(0, n)) {
      auto xdiff = positions[i][0] - positions[start_position][0];
      xdiff = xdiff * xdiff;
      auto ydiff = positions[i][1] - positions[start_position][1];
      ydiff = ydiff * ydiff;
      auto diff = xdiff + ydiff;
      min_time = min(min_time, dp[(1 << n) - 1][i] + sqrt(diff));
    }
  }
  cout << min_time << endl;
  return 0;
}
