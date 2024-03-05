#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return x * x * x + x;
}

int main() {
  int n;
  cin >> n;
  double left = 1;
  double right = n;

  while (left < right) {
    auto mid = (left + right) / 2;

    if (f(mid) < n) {
      left = mid + 0.0001;
    } else {
      right = mid - 0.0001;
    }
  }

  cout << left << endl;

  return 0;
}
