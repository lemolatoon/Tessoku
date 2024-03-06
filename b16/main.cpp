#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  
  vector<int64_t> h;
  h.reserve(n);

  for (const auto _ : views::iota(0, n)) {
    int64_t tmp;
    cin >> tmp;
    h.emplace_back(tmp);
  }

  vector<int64_t> dp(n, 0);
  dp[1] = abs(h[1] - h[0]);

  for (const auto i : views::iota(2, n)) {
    auto one = dp[i - 1] + abs(h[i] - h[i - 1]);
    auto two = dp[i - 2] + abs(h[i] - h[i - 2]);
    dp[i] = min(one, two);
  }

  cout << dp[n - 1] << endl;

  return 0;
}
