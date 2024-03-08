#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, s;
  cin >> n >> s;
  vector<int64_t> a;
  a.reserve(n);

  for (const auto _ : views::iota(0, n)) {
    int64_t tmp;
    cin >> tmp;
    a.emplace_back(tmp);
  }

  // dp[i][j]: possibility of chose cards 1..i, and make j as the sum of them.
  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
  // making 0 from no cards is possible.
  dp[0][0] = true;

  for (const auto i : views::iota(1, n + 1)) {
    for (const auto j : views::iota(0, s + 1)) {
      if (dp[i - 1][j]) {
        // By not choosing card i.
        dp[i][j] = true;
      }

      // NOTE: card index j is 1-origin, while vector a is 0-origin
      if (0 <= j - a[i - 1] && dp[i - 1][j - a[i - 1]]) {
        // By choosing card i.
        dp[i][j] = true;
      }
    }
  }
  if (!dp[n][s]) {
    cout << "-1\n";
    return 0;
  }

  vector<int64_t> chosenCards;

  for (int64_t i = n, j = s;;) {

    if (i == 0 && j == 0) {
      break;
    }

    if (dp[i - 1][j]) {
      i--;
    } else if (0 <= j - a[i - 1] && dp[i - 1][j - a[i - 1]]) {
      chosenCards.emplace_back(i);
      j -= a[i - 1];
      i--;
    } else {
      assert(false && "unreachable");
    }
  }

  cout << chosenCards.size() << endl;

  for (const auto card : chosenCards | views::reverse) {
    cout << card << " ";
  }
  cout << endl;
  return 0;
}
