#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<int64_t> a;
  for (auto count : views::iota(0, n)) {
    int64_t tmp;
    cin >> tmp;
    a.emplace_back(tmp);
  }

  vector<int64_t> unique_a = a;

  std::sort(unique_a.begin(), unique_a.end());

  unique_a.erase(unique(unique_a.begin(), unique_a.end()), unique_a.end());

  vector<int64_t> b;

  for (size_t i : views::iota(static_cast<size_t>(0), a.size())) {
    auto it = lower_bound(unique_a.begin(), unique_a.end(), a[i]);
    b.emplace_back(std::distance( unique_a.begin(), it) + 1);
  }

  for (auto& b_elm : b) {
    cout << b_elm << " ";
  }
  cout << endl;

  return 0;
}
