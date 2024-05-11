#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t q;
  cin >> q;
  set<int64_t> table;
  for ([[maybe_unused]] const auto i : views::iota(0, q)) {
    int64_t kind;
    cin >> kind;
    switch (kind) {
    case 1: {
      int64_t x;
      cin >> x;
      table.insert(x);
      break;
    }
    case 2: {
      int64_t x;
      cin >> x;
      table.erase(x);
      break;
    }
    case 3: {
      int64_t x;
      cin >> x;
      // auto minValOfLargerthanOrEqualToX =
      //     ranges::partition_point(table, [&](auto v) { return v <= x; });
      auto minValOfLargerthanOrEqualToX = table.lower_bound(x);
      if (minValOfLargerthanOrEqualToX == table.end()) {
        cout << "-1" << endl;
      } else {
        cout << *minValOfLargerthanOrEqualToX << endl;
      }
      break;
    }
    }
  }
  return 0;
}
