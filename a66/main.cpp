#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
  vector<int64_t> parent_, rank_, size_;

public:
  explicit UnionFind(int64_t n) : parent_(n, -1), rank_(n, 0), size_(n, 1) {}

  int root(int x) {
    if (parent_[x] == -1) {
      return x;
    } else {
      const auto xRoot = root(parent_[x]);
      parent_[x] = xRoot;
      return xRoot;
    }
  }

  int issame(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    auto xRoot = root(x);
    auto yRoot = root(y);

    if (xRoot == yRoot) {
      return false;
    }

    if (rank_[xRoot] < rank_[yRoot]) {
      swap(xRoot, yRoot);
    }
    // assert(rank[xRoot] >= rank[yRoot]);

    parent_[yRoot] = xRoot;
    if (rank_[xRoot] == rank_[yRoot]) {
      // even though we make higher rank root new root,
      // if both group has same rank, the united group
      // should have incremented rank.
      rank_[xRoot]++;
    }
    size_[xRoot] += size_[yRoot];

    return true;
  }

  int size(int x) { return size_[root(x)]; }
};

int main() {
  int64_t n, q;
  cin >> n >> q;

  auto uf = UnionFind(n);
  for (const auto i : views::iota(0, q)) {
    int64_t qKind, u, v;
    cin >> qKind >> u >> v;
    u--;
    v--;
    if (qKind == 1) {
      // unite
      uf.unite(u, v);
    } else {
      // issame?
      cout << (uf.issame(u, v) ? "Yes\n" : "No\n");
    }
  }
  return 0;
}
