#include <bits/stdc++.h>
#include <limits>
#include <ranges>
using namespace std;

void dfs(vector<set<int64_t>> &edges, vector<int64_t> &visited,
         vector<int64_t> &distance, int64_t v) {
  visited[v] = true;
  for (const auto next_v : edges[v]) {
    if (visited[next_v])
      continue;

    distance[next_v] = min(distance[next_v], distance[v] + 1);
    dfs(edges, visited, distance, next_v);
  }
}

int main() {
  int64_t n, m;
  cin >> n >> m;

  vector<set<int64_t>> edges(n, set<int64_t>());

  for (const auto i : views::iota(0, m)) {
    int64_t a, b;
    cin >> a >> b;
    edges[a - 1].insert(b - 1);
    edges[b - 1].insert(a - 1);
  }

  vector<int64_t> distance(n, numeric_limits<int64_t>::max() - 1);
  distance[0] = 0;
  vector<int64_t> visited(n, false);

  // simple path of 0..n-1
  dfs(edges, visited, distance, 0);

  vector<int64_t> path;
  path.emplace_back(n - 1);
  for (;;) {
    const auto current_v = path.back();
    if (current_v == 0) {
      break;
    }
    for (const auto v : edges[current_v]) {
      if (distance[v] + 1 == distance[current_v]) {
        path.emplace_back(v);
        break;
      }
    }
  }

  for (const auto v : path | views::reverse) {
    cout << v + 1 << " ";
  }
  cout << endl;
  return 0;
}
