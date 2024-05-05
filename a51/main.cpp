#include <iostream>
#include <ranges>
#include <stack>
using namespace std;

int main() {
  int64_t q;
  cin >> q;
  stack<string> st;

  for (const auto i : views::iota(0, q)) {
    int64_t queryKind;
    cin >> queryKind;
    if (queryKind == 1) {
      string name;
      cin >> name;
      st.emplace(name);
    } else if (queryKind == 2) {
      cout << st.top() << endl;
    } else {
      st.pop();
    }
  }
  return 0;
}
