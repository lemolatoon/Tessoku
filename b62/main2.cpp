#include <bits/stdc++.h>
#include <cmath>
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

  vector<bool> visited(n, false);
  stack<int64_t> v_stack;
  vector<int64_t> path;
  v_stack.emplace(0);

  while (!v_stack.empty()) {
    auto v = v_stack.top();
    v_stack.pop();
    if (visited[v]) {
      path.pop_back();
      continue;
    }
    path.emplace_back(v);
    if (v + 1 == n) {
      break;
    }
    visited[v] = true;
    v_stack.emplace(v);
    for (const auto next_v : edges[v]) {
      if (visited[next_v]) {
        continue;
      } else {
        v_stack.emplace(next_v);
      }
    }
  }

  for (const auto v : path) {
    cout << v + 1 << " ";
  }
  cout << endl;

  return 0;
}
