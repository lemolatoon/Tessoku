#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> a = {0};
  vector<int64_t> b = {0, 0};

  for (auto _ : views::iota(1, n)) {
    int64_t tmp;
    cin >> tmp;
    a.emplace_back(tmp);
  }

  for (auto _ : views::iota(2, n)) {
    int64_t tmp;
    cin >> tmp;
    b.emplace_back(tmp);
  }

  vector<int64_t> dp(n, 0);
  dp[1] = a[1];

  for (auto i : views::iota(2, n)) {
    dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i]);
  }

  cout << dp[n - 1] << endl;
  return 0;
}
