#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int buf[10];
  for (int i = 0; i < 10; i++) {
    buf[10 - (i + 1)] = n % 2;
    n /= 2;
  }
  for (int i = 0; i < 10; i++) {
    cout << buf[i];
  }
  cout << "\n";
  return 0;
}
