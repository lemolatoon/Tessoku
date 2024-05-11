#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t q;
  cin >> q;
  set<int64_t> table;
  for ([[maybe_unused]] const auto i : views::iota(0, q)) {
    int64_t kind;
    cin >> kind;
    int64_t x;
    cin >> x;
    switch (kind) {
    case 1: {
      table.insert(x);
      break;
    }
    case 2: {
      if (table.empty()) {
        cout << "-1" << endl;
        continue;
      }
      auto xNext = table.lower_bound(x);
      if (xNext == table.end()) {
        cout << abs(*table.rbegin() - x) << endl;
      } else {
        array<int64_t, 2> candidates = {0, numeric_limits<int64_t>::max()};
        candidates[0] = abs(*xNext - x);
        if (xNext != table.begin()) {
          xNext--;
          candidates[1] = abs(*xNext - x);
        }
        cout << ranges::min(candidates) << endl;
      }
      break;
    }
    }
  }
  return 0;
}
