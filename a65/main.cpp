#include <bits/stdc++.h>
#include <ranges>
using namespace std;

int main() {
  int64_t n;
  cin >> n;

  vector<vector<int64_t>> subordinates(n, vector<int64_t>());

  for (const auto i : views::iota(1, n)) {
    int64_t a;
    cin >> a;
    a--;

    subordinates[a].push_back(i);
  }

  vector<int64_t> totalSubordinates(n, 0);
  for (const auto i : views::iota(0, n) | views::reverse) {
    for (const auto directSubordinate : subordinates[i]) {
      totalSubordinates[i] += totalSubordinates[directSubordinate] + 1;
    }
  }

  for (const auto totalSubordinate : totalSubordinates) {
    cout << totalSubordinate << " ";
  }
  cout << endl;

  return 0;
}
