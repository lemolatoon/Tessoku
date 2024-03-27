#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> x(n);
  vector<int64_t> y(n);

  for (const auto i : views::iota(0, n)) {
    cin >> x[i];
    cin >> y[i];
  }

  // first consider only x.
  vector<int64_t> max_length_with_last_val_index(
      n, numeric_limits<int64_t>::min() / 2);
  vector<int64_t> min_last_val_with_length_of(
      n, numeric_limits<int64_t>::max() / 2);

  max_length_with_last_val_index[0] = 1;
  min_last_val_with_length_of[0] = x[0];

  for (const auto i : views::iota(1, n)) {
    auto pos_iter =
        ranges::lower_bound(min_last_val_with_length_of | views::take(i), x[i]);

    // since index == length.
    auto length = std::distance(min_last_val_with_length_of.begin(), pos_iter);

    max_length_with_last_val_index[i] = length + 1;

    min_last_val_with_length_of[length] =
        min(min_last_val_with_length_of[length], x[i]);
  }

  auto max_length_iter = ranges::max_element(max_length_with_last_val_index);
  size_t last_val_index =
      std::distance(max_length_with_last_val_index.begin(), max_length_iter);

  auto possibleIndexes = vector<int64_t>(0);

  for (;;) {
    possibleIndexes.emplace_back(last_val_index);
    auto length = max_length_with_last_val_index[last_val_index];

    auto next_last_val = min_last_val_with_length_of[length - 1];
    for (const auto i : views::iota(static_cast<size_t>(0), x.size()) |
                            views::take(last_val_index) | views::reverse) {
      // cout << "last_val_index: " << last_val_index << ", x[" << i
      //      << "]: " << x[i] << ", next_last_val: " << next_last_val << endl;
      // if (x[i] == next_last_val) {
      //   last_val_index = i;
      //   break;
      // }
      if (x[i] == next_last_val) {
        last_val_index = i;
        break;
      }
    }

    if (length == 1) {
      possibleIndexes.emplace_back(last_val_index);
      break;
    }
  }
  for (const auto v : possibleIndexes) {
    cout << v << endl;
  }

  return 0;
}
