#include <bits/stdc++.h>
#include <cstdint>
#include <ranges>
using namespace std;

int64_t nibutan(int64_t n, int64_t k, std::vector<int64_t>& a) {
  int64_t ans = 0;

  for (auto less_index : std::views::iota(static_cast<size_t>(0), a.size())) {
    auto less_val = a[less_index];

    auto cond = [&](int64_t larger_val) {
      return larger_val - less_val <= k;
    };

    // itは条件を満たさない最初の場所
    // auto it = ranges::partition_point(a, cond);
    // auto distance = std::distance(a.begin(), it);

    auto left = 0;
    auto right = a.size();
    while (left < right) {
      // left != right より、 mid < right は常に成り立つので、index out of range
      // は起き得ない
      auto mid = (left + right) / 2;

      if (cond(a[mid])) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    auto distance = left;

    ans += distance - less_index - 1;
  }

  return ans;
}

int64_t shakutori(int64_t n, int64_t k, std::vector<int64_t>& a) {
  int64_t ans = 0;
  size_t current_index = 0;
  for (const auto less_val_index: views::iota(static_cast<size_t>(0), a.size())) {
    const auto less_val = a[less_val_index];
    const auto cond = [&](const auto larger_val) {
      return larger_val - less_val <= k;
    };


    while (cond(a[current_index]) && current_index < a.size()) {
      current_index++;
    }

    // (less_val_index, current_index) の開区間の個数
    const auto n_satisfy_with_less_val = current_index - less_val_index - 1;

    ans += n_satisfy_with_less_val;
  }

  return ans;
}

int main() {
  int64_t n, k;
  cin >> n >> k;
  std::vector<int64_t> a;
  for (int64_t i = 0; i < n; i++) {
    int64_t tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  // auto ans = nibutan(n, k, a);
  auto ans = shakutori(n, k, a);
  cout << ans << endl;
  return 0;
}
