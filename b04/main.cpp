#include <bits/stdc++.h>
using namespace std;

int main() {
  std::string n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '1') ans += pow(2, n.size() - (i + 1));
  }
  cout << ans << "\n";
  return 0;
}
