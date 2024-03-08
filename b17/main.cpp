#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> h;

  for (const auto _ : views::iota(0, n)) {
    int64_t tmp;
    cin >> tmp;
    h.emplace_back(tmp);
  }

  vector<int64_t> dp(n, 0);
  dp[1] = abs(h[1] - h[0]);

  for (const auto i : views::iota(2, n)) {
    dp[i] =
        min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
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

    if (dp[i] == dp[i - 1] + abs(h[i] - h[i - 1])) {
      i = i - 1;
    } else if (dp[i] == dp[i - 2] + abs(h[i] - h[i - 2])) {
      i = i - 2;
    } else {
      assert(false && "unreachable");
    }
  }

  cout << route_rev.size() << endl;
  for (const auto route : route_rev | views::reverse) {
    cout << route + 1 << " ";
  }
  cout << endl;
  return 0;
}
