#include <bits/stdc++.h>
using namespace std;

bool is_less_than_answer(double x, int n) {
  auto f_x = x * x * x + x;

  return f_x < n;
}

double f(double x) {
  return x * x * x + x;
}

int main() {
  int n;
  cin >> n;
  double left = 1;
  double right = n;

  while (right - left < 0.001) {
    auto mid = (left + right) / 2;

    if (is_less_than_answer(mid, n)) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << left << endl;

  return 0;
}
