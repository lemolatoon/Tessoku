#include <iostream>
#include <queue>
#include <ranges>
using namespace std;

int main() {
  int64_t q;
  cin >> q;

  queue<string> que;

  for (const auto i : views::iota(0, q)) {
    int64_t queryKind;
    cin >> queryKind;
    if (queryKind == 1) {
      string name;
      cin >> name;
      que.emplace(name);
    } else if (queryKind == 2) {
      cout << que.front() << endl;
    } else {
      que.pop();
    }
  }

  return 0;
}
