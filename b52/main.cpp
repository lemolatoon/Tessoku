#include <iostream>
#include <queue>
using namespace std;

int main() {
  int64_t n, x;
  cin >> n >> x;
  x--;

  string a;
  cin >> a;

  queue<int64_t> que;
  que.emplace(x);
  a[x] = '@';

  while (!que.empty()) {
    auto pos = que.front();
    que.pop();
    if (a[pos - 1] == '.') {
      a[pos - 1] = '@';
      que.emplace(pos - 1);
    }
    if (a[pos + 1] == '.') {
      a[pos + 1] = '@';
      que.emplace(pos + 1);
    }
  }

  for (const auto c : a) {
    cout << c;
  }
  cout << endl;

  return 0;
}
