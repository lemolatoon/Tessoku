#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int64_t> box[4];

  for (int i : views::iota(0, 4)) {
    for (int count : views::iota(0, n)) {
      int64_t tmp;
      cin >> tmp;

      box[i].emplace_back(tmp);
    }
  }

  vector<int64_t> box_p;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      box_p.emplace_back(box[0][i] + box[1][j]);
    }
  }

  vector<int64_t> box_q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      box_q.emplace_back(box[2][i] + box[3][j]);
    }
  }

  std::sort(box_p.begin(), box_p.end());
  std::sort(box_q.begin(), box_q.end());

  bool ok = false;
  for (auto p_elm : box_p) {
    auto it = lower_bound(box_q.begin(), box_q.end(), k - p_elm);

    if (it != box_q.end() && *it == k - p_elm) {
      ok = true;
      break;
    }
  }

  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
