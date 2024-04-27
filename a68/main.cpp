#include <bits/stdc++.h>
using namespace std;
class UnionFind {
private:
  vector<int64_t> parent_, rank_, size_;

public:
  explicit UnionFind(int64_t n) : parent_(n, -1), rank_(n, 0), size_(n, 1) {}

  int64_t root(int64_t x) {
    if (parent_[x] == -1) {
      return x;
    } else {
      return parent_[x] = root(parent_[x]);
    }
  }

  bool issame(int64_t x, int64_t y) { return root(x) == root(y); }

  bool unite(int64_t x, int64_t y) {
    auto xRoot = root(x);
    auto yRoot = root(y);

    if (xRoot == yRoot) {
      return false;
    }

    if (rank_[xRoot] < rank_[yRoot]) {
      swap(xRoot, yRoot);
    }

    parent_[yRoot] = xRoot;

    if (rank_[xRoot] == rank_[yRoot]) {
      rank_[xRoot]++;
    }

    size_[xRoot] += size_[yRoot];

    return true;
  }

  int64_t size(int64_t x) { return size_[root(x)]; }
};

int main() {
  int64_t n, m;
  cin >> n >> m;
  struct Edge {
    int64_t a, b;
    int64_t length;
  };
  vector<Edge> edgeList(m);
  for (const auto i : views::iota(0, m)) {
    Edge e;
    cin >> e.a >> e.b >> e.length;
    e.a--;
    e.b--;
    edgeList.emplace_back(e);
  }

  ranges::sort(edgeList, ranges::greater{}, &Edge::length);

  UnionFind uf(n);
  int64_t sumLength = 0;
  for (const auto e : edgeList) {
    if (uf.issame(e.a, e.b)) {
      continue;
    }

    uf.unite(e.a, e.b);
    sumLength += e.length;
  }
  cout << sumLength << endl;
  return 0;
}
