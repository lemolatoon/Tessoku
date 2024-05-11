#include <iostream>
#include <map>
#include <ranges>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  std::map<int64_t, int64_t> counts;

  for ([[maybe_unused]] const auto i : views::iota(0, n)) {
    int64_t x;
    cin >> x;
    counts.try_emplace(x, 0);
    counts[x]++;
  }

  int64_t sum = 0;
  for (const auto [k, v] : counts) {
    sum += v * (v - 1) / 2;
  }
  cout << sum << endl;
  return 0;
}
