#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n;

  vector<int> hit_acc{0};
  vector<int> miss_acc{0};
  hit_acc.reserve(n + 1);
  miss_acc.reserve(n + 1);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 0) {
      hit_acc.push_back(hit_acc.back() + 0);
      miss_acc.push_back(miss_acc.back() + 1);
    } else {
      hit_acc.push_back(hit_acc.back() + 1);
      miss_acc.push_back(miss_acc.back() + 0);
    }
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int n_miss = miss_acc[r] - miss_acc[l - 1];
    int n_hit = hit_acc[r] - hit_acc[l - 1];
    if (n_hit == n_miss) {
      cout << "draw\n";
    } else if (n_hit > n_miss) {
      cout << "win\n";
    } else {
      cout << "lose\n";
    }
  }

  return 0;
}
