#include <iostream>
#include <queue>
#include <ranges>
using namespace std;

int main() {
  int64_t q;
  cin >> q;

  priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> products;
  for ([[maybe_unused]] const auto i : views::iota(0, q)) {
    int64_t kind;
    cin >> kind;
    if (kind == 1) {
      int64_t x;
      cin >> x;
      products.emplace(x);
    } else if (kind == 2) {
      cout << products.top() << endl;
    } else {
      products.pop();
    }
  }
  return 0;
}
