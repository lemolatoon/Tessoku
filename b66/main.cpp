#include <bits/stdc++.h>
#include <ranges>
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
      const auto xRoot = root(parent_[x]);
      parent_[x] = xRoot;
      return xRoot;
    }
  }

  int64_t issame(int64_t x, int64_t y) { return root(x) == root(y); }

  bool unite(int64_t x, int64_t y) {
    auto xRoot = root(x);
    auto yRoot = root(y);

    if (xRoot == yRoot) {
      return false;
    }

    if (rank_[xRoot] < rank_[yRoot]) {
      swap(xRoot, yRoot);
    }
    // rank_[xRoot] >= rank_[yRoot]
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

  vector<pair<int64_t, int64_t>> routes(m);
  for (const auto i : views::iota(0, m)) {
    cin >> routes[i].first >> routes[i].second;
  }

  struct Query {
    int kind;
    int64_t a, b;
    int64_t routeNum;
  };
  int64_t q;
  cin >> q;
  vector<Query> queries(q);

  set<int64_t> initiallyConnectedRoutes;
  for (const auto i : views::iota(0, m)) {
    initiallyConnectedRoutes.insert(i);
  }
  for (const auto i : views::iota(0, q)) {
    cin >> queries[i].kind;
    if (queries[i].kind == 1) {
      cin >> queries[i].routeNum;
      initiallyConnectedRoutes.erase(queries[i].routeNum - 1);
    } else {
      cin >> queries[i].a >> queries[i].b;
    }
  }

  auto uf = UnionFind(n);
  for (const auto connected : initiallyConnectedRoutes) {
    const auto [x, y] = routes[connected];
    // 0-index
    uf.unite(x - 1, y - 1);
  }
  vector<bool> answers;

  for (const auto q : queries | views::reverse) {
    if (q.kind == 1) {
      const auto routeNum = q.routeNum;
      const auto [x, y] = routes[routeNum - 1];
      uf.unite(x - 1, y - 1);
    } else {
      const auto a = q.a;
      const auto b = q.b;
      answers.emplace_back(uf.issame(a - 1, b - 1));
    }
  }

  for (const auto ansewr : answers | views::reverse) {
    if (ansewr) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
