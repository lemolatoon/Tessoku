#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> a{};
  a.reserve(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

      for (int k = 0; k < n; k++) {
        if (i == j || j == k || k == i) continue;
        if (a[i] + a[j] + a[k] == 1000) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
