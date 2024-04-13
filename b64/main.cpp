#include <bits/stdc++.h>
#include <limits>
#include <queue>
using namespace std;

int main() {
  int64_t n, m;
  cin >> n >> m;

  using EdgeInfo = pair<int64_t, int64_t>;
  // edge, len
  vector<set<EdgeInfo>> adjacencyLists(n, set<EdgeInfo>());

  for (const auto i : views::iota(0, m)) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adjacencyLists[a].insert(EdgeInfo{b, c});
    adjacencyLists[b].insert(EdgeInfo{a, c});
  }
  vector<int64_t> approxDistances(n, numeric_limits<int64_t>::max() - 10000);
  vector<bool> isDetermined(n, false);
  // approxDist, edge
  using EdgeInfo2 = pair<int64_t, int64_t>;
  priority_queue<EdgeInfo2, vector<EdgeInfo2>, greater<EdgeInfo2>> pq;
  approxDistances[0] = 0;
  pq.emplace(EdgeInfo2{approxDistances[0], 0});

  while (!pq.empty()) {
    auto [distance, edge] = pq.top();
    pq.pop();

    if (isDetermined[edge]) {
      continue;
    }
    isDetermined[edge] = true;

    for (const auto [nextEdge, len] : adjacencyLists[edge]) {
      if (isDetermined[nextEdge]) {
        continue;
      }
      if (approxDistances[edge] + len < approxDistances[nextEdge]) {
        approxDistances[nextEdge] = approxDistances[edge] + len;
        pq.emplace(EdgeInfo2{approxDistances[nextEdge], nextEdge});
      }
    }
  }

  vector<int64_t> routeReversed;
  routeReversed.reserve(approxDistances[n - 1]);

  routeReversed.emplace_back(n - 1);
  int64_t currentWatchingEdge = n - 1;
  while (currentWatchingEdge != 0) {
    for (const auto [edge, len] : adjacencyLists[currentWatchingEdge]) {
      if (approxDistances[currentWatchingEdge] == approxDistances[edge] + len) {
        routeReversed.emplace_back(edge);
        currentWatchingEdge = edge;
        continue;
      }
    }
  }

  for (const auto edge : routeReversed | views::reverse) {
    cout << edge + 1 << " ";
  }
  cout << endl;

  return 0;
}
