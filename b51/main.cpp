#include <iostream>
#include <ranges>
#include <stack>
using namespace std;

int main() {
  string q;
  cin >> q;

  stack<int64_t> st;

  for (const auto i : views::iota(0u, q.length())) {
    if (q[i] == '(') {
      st.emplace(i);
    } else {
      cout << st.top() + 1 << " " << i + 1 << endl;
      st.pop();
    }
  }

  return 0;
}
