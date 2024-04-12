#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n, m;
  cin >> n >> m;

  struct EdgeInfo {
  private:
    pair<int64_t, int64_t> inner;
    int64_t &edgeMut() { return inner.first; }
    int64_t &lengthMut() { return inner.second; }

  public:
    EdgeInfo(int64_t edge, int64_t length) : inner(pair{edge, length}) {}
    int64_t edge() { return inner.first; }
    int64_t length() { return inner.second; }
    int64_t edge() const { return inner.first; }
    int64_t length() const { return inner.second; }

    void updateLengthIfLess(int64_t candidate) {
      lengthMut() = min(length(), candidate);
    }

    auto operator<=>(const EdgeInfo &x) const {
      return this->inner <=> x.inner;
    }
  };

  vector<set<EdgeInfo>> adjacencyLists(n, set<EdgeInfo>());

  for (const auto i : views::iota(0, m)) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adjacencyLists[a].insert({b, c});
    adjacencyLists[b].insert({a, c});
  }

  vector<int64_t> approxDistances(n, numeric_limits<int64_t>::max() - 10000);
  vector<bool> isDetermined(n, false);
  approxDistances[0] = 0;
  using DistEdge = pair<int64_t, int64_t>;
  priority_queue<DistEdge, vector<DistEdge>, greater<DistEdge>> pq;
  pq.push({approxDistances[0], 0});
  while (!pq.empty()) {
    auto [nextDist, nextEdge] = pq.top();
    pq.pop();
    if (isDetermined[nextEdge])
      continue;
    isDetermined[nextEdge] = true;

    for (auto &adjacency : adjacencyLists[nextEdge]) {
      if (isDetermined[adjacency.edge()])
        continue;

      auto routeLen = nextDist + adjacency.length();
      if (routeLen < approxDistances[adjacency.edge()]) {
        approxDistances[adjacency.edge()] = routeLen;

        pq.push({routeLen, adjacency.edge()});
      }
    }
  }

  for (const auto i : views::iota(0, n)) {
    if (approxDistances[i] == numeric_limits<int64_t>::max() - 10000) {
      cout << "-1\n";
      continue;
    }
    cout << approxDistances[i] << endl;
  }

  return 0;
}
