#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a;
  a.reserve(n);
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }

  sort(a.begin(), a.end());

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
    cout << pos << "\n";
  }

  return 0;
}
