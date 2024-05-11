#include <bits/stdc++.h>
#include <cstdint>
#include <ranges>
using namespace std;

int64_t sumDigits(int64_t n) {
  int64_t result = 0;
  while (n > 0) {
    result += n % 10;
    n /= 10;
  }
  return result;
}

int main() {
  int64_t n, k;
  cin >> n >> k;

  const int64_t numMaxBit = 30;
  vector<vector<int64_t>> operated(numMaxBit, vector<int64_t>(n + 1));

  for (const auto i : views::iota(1, n + 1)) {
    operated[0][i] = i - sumDigits(i);
  }

  for (const auto bit : views::iota(1, numMaxBit)) {
    for (const auto i : views::iota(1, n + 1)) {
      operated[bit][i] = operated[bit - 1][operated[bit - 1][i]];
    }
  }

  for ([[maybe_unused]] const auto i : views::iota(1, n + 1)) {
    int64_t result = i;
    for (const auto bit : views::iota(0, numMaxBit)) {
      if ((k & (1 << bit)) != 0) {
        result = operated[bit][result];
      }
    }
    cout << result << endl;
  }
  return 0;
}
