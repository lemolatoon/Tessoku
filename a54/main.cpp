#include <iostream>
#include <map>
#include <ranges>
using namespace std;

int main() {
  int64_t q;
  cin >> q;
  std::map<string, int64_t> scores;
  for ([[maybe_unused]] const auto i : views::iota(0, q)) {
    int64_t kind;
    cin >> kind;
    if (kind == 1) {
      string x;
      int64_t y;
      cin >> x >> y;
      scores.insert({x, y});
    } else {
      string name;
      cin >> name;
      cout << scores.at(name) << endl;
    }
  }
  return 0;
}
