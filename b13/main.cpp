#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;

  vector<int64_t> a;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  vector<int64_t> acc = {0};

  for (int i = 0; i < n; i++) {
    acc.push_back(acc.back() + a[i]);
  }

  int right = 1;
  int64_t ans = 0;
  for (int left = 0; left < n; left++) {
    while (acc[right] - acc[left] <= k && right <= n) {
      right++;
    }

    ans += right - left - 1;
  }

  cout << ans << endl;

  return 0;
}
