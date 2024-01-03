#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;

  unsigned int count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (1 <= k - i - j && k - i - j <= n) {
        count++;
      }
    }
  }
  cout << count << "\n";
}
