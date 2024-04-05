#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n, m;
  cin >> n >> m;
  vector<set<int64_t>> vertexes(static_cast<size_t>(n), set<int64_t>());

  for (const auto _ : views::iota(0, m)) {
    int64_t a, b;
    cin >> a >> b;
    vertexes[a - 1].insert(b);
    vertexes[b - 1].insert(a);
  }
  size_t max = numeric_limits<size_t>::min();
  int64_t max_index = 0;
  for (const auto i : views::iota(0, n)) {
    if (max < vertexes[i].size()) {
      max = vertexes[i].size();
      max_index = i;
    }
  }
  cout << max_index + 1 << endl;
  return 0;
}
