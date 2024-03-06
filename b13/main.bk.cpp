#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;

  vector<int64_t> a;
  vector<int64_t> acc = {0};

  for (auto i : views::iota(0, n)) {
    int64_t tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  std::sort(a.begin(), a.end());

  for (auto& elm : a) {
    acc.push_back(acc.back() + elm);
  }

  uint64_t ans = 0;

  // current_index in [0, n]
  size_t current_index = 0;

  for (auto purchase_begin : views::iota(static_cast<size_t>(0), a.size())) {
    // purchase_begin in [0, n)

    // 半開区間 [purchase_begin, purchase_until) について、条件があっているか確かめる。
    auto cond = [&](auto purchase_until) {
      return acc[purchase_until] - acc[purchase_begin] <= k;
    };

    while (cond(current_index) && current_index < acc.size()) {
      current_index++;
    }
    // [purchase_begin, current_index - 1) について、条件があっている。
    // つまり、
    // [purchase_begin, purchase_begin + 1)
    // ...
    // [purchase_begin, current_index - 1)
    // までの、 (current_index - 1) - (purchase_begin + 1) + 1 通りある。

    cout << "(" << acc[purchase_begin] << ", " << acc[purchase_begin + 1] << ")" << endl;
    cout << "(" << acc[purchase_begin] << ", " << acc[current_index - 1] << ")" << endl;
    cout << current_index - purchase_begin - 1 << endl;

    ans += current_index - purchase_begin - 1;
  }

  cout << ans << endl;

  return 0;
}
