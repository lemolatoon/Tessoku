#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, m;
  cin >> n >> m;

  vector<set<int64_t>> edges(n, set<int64_t>());

  for (const auto _ : views::iota(0, m)) {
    int64_t a, b;
    cin >> a >> b;

    edges[a - 1].insert(b - 1);
    edges[b - 1].insert(a - 1);
  }

  vector<int64_t> distances(n, -1);
  queue<int64_t> q;
  q.emplace(0);
  distances[0] = 0;

  while (!q.empty()) {
    auto v = q.front();
    q.pop();

    for (const auto next_v : edges[v]) {
      if (distances[next_v] != -1)
        continue;
      distances[next_v] = distances[v] + 1;

      q.emplace(next_v);
    }
  }

  for (const auto d : distances) {
    cout << d << endl;
  }
  return 0;
}
