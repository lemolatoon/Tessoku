#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <ranges>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<pair<int64_t, int64_t>> boxes(n);

  for (const auto i : views::iota(0, n)) {
    int64_t x, y;
    cin >> x >> y;
    boxes[i] = {x, y};
  }

  // By sorting X will be sorted.
  // and for i s.t x[i] == x[i + 1]
  // then y[i] >= y[i + 1]
  // Hense, if we calculate maximum length of sub monotonic increasing sequence,
  // which will make also x sub monotonic increasing sequence.
  // And we can avoid for the same x, pick only one x as the sub sequence.
  ranges::sort(boxes, [](auto p1, auto p2) {
    const auto [x1, y1] = p1;
    const auto [x2, y2] = p2;
    if (x1 == x2) {
      return y1 > y2;
    }

    return x1 < x2;
  });

  vector<int64_t> max_length_with_last_val_index(
      n, numeric_limits<int64_t>::min() / 2);
  vector<int64_t> min_last_val_with_length_of(
      n, numeric_limits<int64_t>::max() / 2);

  max_length_with_last_val_index[0] = 1;
  min_last_val_with_length_of[0] = boxes[0].second;

  for (const auto i : views::iota(1, n)) {
    auto pos_iter = ranges::lower_bound(
        min_last_val_with_length_of | views::take(i), boxes[i].second);

    // since index == length.
    auto length = std::distance(min_last_val_with_length_of.begin(), pos_iter);

    max_length_with_last_val_index[i] = length + 1;

    min_last_val_with_length_of[length] =
        min(min_last_val_with_length_of[length], boxes[i].second);
  }

  auto max_length = ranges::max(max_length_with_last_val_index);
  cout << max_length << endl;

  return 0;
}
