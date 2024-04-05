#include <bits/stdc++.h>
using namespace std;

void dfs(vector<set<int64_t>> &vertexes, vector<bool> &visited,
         int64_t vertex) {
  visited[vertex] = true;
  for (const auto next_v : vertexes[vertex]) {
    if (visited[next_v])
      continue;

    dfs(vertexes, visited, next_v);
  }
}

int main() {
  int64_t n, m;
  cin >> n >> m;

  vector<set<int64_t>> vertexes{static_cast<size_t>(n), set<int64_t>{}};

  for (const auto _ : views::iota(0, m)) {
    int64_t a, b;
    cin >> a >> b;

    vertexes[a - 1].insert(b - 1);
    vertexes[b - 1].insert(a - 1);
  }

  vector<bool> visited(static_cast<size_t>(n), false);

  dfs(vertexes, visited, 0);

  if (ranges::all_of(visited, [](auto f) { return f; })) {
    cout << "The graph is connected.\n";
  } else {
    cout << "The graph is not connected.\n";
  }

  return 0;
}
