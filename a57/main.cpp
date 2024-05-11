#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, q;
  cin >> n >> q;
  vector<int64_t> a(n);
  for (const auto i : views::iota(0, n)) {
    cin >> a[i];
    a[i]--;
  }

  const size_t numMaxBit = 32;
  vector<vector<int64_t>> moveTo(numMaxBit, vector<int64_t>(n));

  // After 2^0 = 1 day passed
  for (const auto i : views::iota(0, n)) {
    moveTo[0][i] = a[i];
  }

  for (const auto bit : views::iota(1u, numMaxBit)) {
    for (const auto i : views::iota(0, n)) {
      // moveTo[bit - 1][i] is a position after 2^{bit-1} days from position i.
      moveTo[bit][i] = moveTo[bit - 1][moveTo[bit - 1][i]];
    }
  }

  for ([[maybe_unused]] const auto i : views::iota(0, q)) {
    int64_t x, y;
    cin >> x >> y;
    x--;
    int currentPosition = x;
    for (const auto bit : views::iota(0u, numMaxBit) | views::reverse) {
      if ((y & (1 << bit)) != 0) {
        currentPosition = moveTo[bit][currentPosition];
      }
    }
    cout << currentPosition + 1 << endl;
  }
  return 0;
}
