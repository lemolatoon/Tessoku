#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t >> n;
  vector<int> n_clerk_diff = vector<int>(t + 1, 0); // -1 ~ t - 1

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    n_clerk_diff[l + 1]++;
    n_clerk_diff[r + 1]--;
  }
  auto n_clerk = std::move(n_clerk_diff);

  for (int i = 1; i <= t; i++) {
    n_clerk[i] += n_clerk[i - 1];
    cout << n_clerk[i] << "\n";
  }

  return 0;
}
