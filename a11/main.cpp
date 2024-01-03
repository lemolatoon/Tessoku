#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a;
  a.reserve(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  int l = 0;
  int r = a.size() - 1;
  int index = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == x) {
      index = mid;
      break;
    }
    if (a[mid] < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << index + 1 << "\n";

  return 0;
}
