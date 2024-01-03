#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, n;
  cin >> d >> n;

  vector<int> n_attendant_diff = vector<int>(d + 1, 0);

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    n_attendant_diff[l] += 1;
    n_attendant_diff[r + 1] -= 1;
  }

  for (int i = 1; i <= d; i++) {
    n_attendant_diff[i] += n_attendant_diff[i - 1];
  }

  for (int i = 1; i <= d; i++) {
    cout << n_attendant_diff[i] << "\n";
  }

  return 0;
}
