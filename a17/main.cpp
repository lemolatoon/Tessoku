#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a, b;
  a.reserve(n - 1);
  b.reserve(n - 2);

  for (auto _ : views::iota(0, n - 1)) {
    int64_t tmp;
    cin >> tmp;
    a.emplace_back(tmp);
  }

  for (auto _ : views::iota(0, n - 2)) {
    int64_t tmp;
    cin >> tmp;
    b.emplace_back(tmp);
  }

  vector<int64_t> dp(n, 0);
  dp[1] = a[0];

  for (auto i : views::iota(2, n)) {
    dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + b[i - 2]);
  }

  vector<int64_t> route_rev;
  for (int64_t i = n - 1;;) {
    route_rev.emplace_back(i);

    if (i == 0) {
      break;
    } else if (i == 1) {
      route_rev.emplace_back(0);
      break;
    }

    // cout << "cond: "
    //      << "a[" << i << "]: " << a[i] << ", b[" << i << "]: " << b[i]
    //      << ", dp[" << i << "]: " << dp[i] << ", dp[" << i
    //      << " - 1]: " << dp[i - 1] << ", dp[" << i << " - 2]: " << dp[i - 2]
    //      << endl;
    if (dp[i - 1] + a[i - 1] == dp[i]) {
      i = i - 1;
    } else if (dp[i - 2] + b[i - 2] == dp[i]) {
      i = i - 2;
    } else {
      assert(false && "unreachable");
    }
  }

  cout << route_rev.size() << endl;
  for (const auto route : route_rev | views::reverse) {
    cout << route + 1 << (route == route_rev.front() ? "\n" : " ");
  }

  return 0;
}
