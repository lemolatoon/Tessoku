#include <bits/stdc++.h>
#include <limits>
#include <ranges>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);

  for (const auto i : views::iota(0, n)) {
    cin >> a[i];
  }

  // dp[i]: the minimum length of sub monotonic increasing sequence
  vector<int64_t> dp(n, numeric_limits<int64_t>::min() / 2);
  // l[i]: the minimum value that can be last value of sub monotonic increasing sequence of length i.
  // i.e) min({A_k : dp[k] = i for all k})
  vector<int64_t> l(n, numeric_limits<int64_t>::max() / 2);
  // sub seq with only one value is length 1.
  dp[0] = 1;
  // the last minimum value of sub seq with only a[0] is a[0].
  l[0] = a[0];

  for (const auto i : views::iota(1, n)) {
    auto pos = ranges::lower_bound(l | views::take(i), a[i]);
    // the length (length) sub sequence lasts with the value that is less than a[i];
    auto length = std::distance(l.begin(), pos);

    // Since above, a[i] can be lasts to the sub sequence whose length == index + 1
    dp[i] = length + 1;
    // NOTICE: 0-indexed
    l[length] =  a[i];
  }

  cout << ranges::max(dp) << endl;

  return 0;
}
