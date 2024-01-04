#include <bits/stdc++.h>
using namespace std;

#define int long long

struct result {
  int printed_until_t;
  int printed_until_t_minus_1;
};

struct result n_printed_until(int t, const vector<int> &printer_speeds) {
  int sum_prev = 0;
  int sum = 0;
  for (auto printer_speed : printer_speeds) {
    if (t - 1 >= 0) {
      sum_prev += (t - 1) / printer_speed;
    }
    sum += t / printer_speed;
  }

  return (struct result){sum, sum_prev};
}

const int T_MAX = 1000000000;
int32_t main() {
  int n, k;
  cin >> n >> k;
  vector<int> printer_speeds;
  printer_speeds.reserve(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    printer_speeds.push_back(tmp);
  }

  int t = -1;

  int l = 1;
  int r = T_MAX;
  while (l <= r) {
    int mid = (l + r) / 2;
    struct result result = n_printed_until(mid, printer_speeds);
    if (result.printed_until_t_minus_1 < k && k <= result.printed_until_t) {
      t = mid;
      break;
    }
    if (result.printed_until_t < k) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << t << "\n";
  return 0;
}
