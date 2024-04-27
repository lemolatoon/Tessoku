#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, t;
  cin >> n >> t;

  vector<vector<int64_t>> subordinates(n, vector<int64_t>());
  for (const auto i : views::iota(0, n - 1)) {
    int64_t a, b;
    cin >> a >> b;
    a--;
    b--;
    subordinates[a].emplace_back(b);
  }

  vector<int64_t> depth(n, 0);
  for (const auto i : views::iota(0, n) | views::reverse) {
    if (subordinates[i].empty()) {
      continue;
    }
    depth[i] =
        ranges::max(subordinates[i] | views::transform([&](auto subordinate) {
                      return depth[subordinate];
                    })) +
        1;
  }

  for (const auto depth : depth) {
    cout << depth << " ";
  }
  cout << endl;
  return 0;
}
