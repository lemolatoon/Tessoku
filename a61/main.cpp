#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

int main() {
  int64_t n, m;
  cin >> n >> m;

  vector<set<int64_t>> vertexes(n, set<int64_t>());
  for (const auto _ : views::iota(0, m)) {
    int64_t from, to;
    cin >> from >> to;

    vertexes[from - 1].insert(to - 1);
    vertexes[to - 1].insert(from - 1);
  }

  for (const auto i : views::iota(static_cast<size_t>(0), vertexes.size())) {
    const auto adjacent_vertexes = vertexes[i];
    cout << i + 1 << ": "
         << "{";
    auto n_vertex = adjacent_vertexes.size();
    size_t vertex_index = 0;
    for (const auto v : adjacent_vertexes) {
      cout << v + 1;
      if (vertex_index != n_vertex - 1) {
        cout << ", ";
      }
      vertex_index += 1;
    }
    cout << "}\n";
  }
  return 0;
}
