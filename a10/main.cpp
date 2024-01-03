#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 100000;
int N[N_MAX];
// index: 0, N_MAX + 1は番兵
int cumulative_sum_l[N_MAX + 2];
int cumulative_sum_r[N_MAX + 2];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> N[i];
  }

  for (int i = 1; i <= N_MAX; i++) {
    cumulative_sum_l[i] = max(N[i], cumulative_sum_l[i - 1]);
    int index_r = N_MAX + 1 - i;
    cumulative_sum_r[index_r] = max(N[index_r], cumulative_sum_r[index_r + 1]);
  }

  int d;
  cin >> d;
  for (int i = 0; i < d; i++) {
    int l, r;
    cin >> l >> r;
    int max_cap = max(cumulative_sum_l[l - 1], cumulative_sum_r[r + 1]);
    cout << max_cap << "\n";
  }

  return 0;
}
