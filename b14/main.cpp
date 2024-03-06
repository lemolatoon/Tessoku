#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int64_t> a;
  vector<int64_t> b;
  for (auto count : views::iota(0, n / 2)) {
    int64_t tmp;
    cin >> tmp;

    a.emplace_back(tmp);
  }

  for (auto count : views::iota(n / 2, n)) {
    int64_t tmp;
    cin >> tmp;

    b.emplace_back(tmp);
  }

  unordered_set<int64_t> box_p;
  vector<int64_t> box_q;

  const int64_t aSizeBitMax = 1 << (a.size() + 1);
  for (int64_t bits = 0; bits < aSizeBitMax; bits++) {
    int64_t sum = 0;
    for (int i = 0; i < a.size(); i++) {
      auto selected = (bits & (1 << i)) != 0;
      if (selected) sum += a[i];
    }
    box_p.emplace(sum);
  }

  const int64_t bSizeBitMax = 1 << (b.size() + 1);
  for (int64_t bits = 0; bits < bSizeBitMax; bits++) {
    int64_t sum = 0;
    for (int i = 0; i < b.size(); i++) {
      auto selected = (bits & (1 << i)) != 0;
      if (selected) sum += b[i];
    }
    box_q.emplace_back(sum);
  }

  bool ok = false;
  for (auto &q_elm : box_q) {
    auto it = box_p.find(k - q_elm);
    if (it != box_p.end()) {
      ok = true;
      break;
    }
  }

  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
