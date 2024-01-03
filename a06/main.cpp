#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> acc{0};
  acc.reserve(n + 1);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    acc.push_back(acc.back() + a);
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << acc[r] - acc[l - 1] << "\n";
  }
}
