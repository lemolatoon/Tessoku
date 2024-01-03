#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> x;
  x.emplace_back(vector<int>(w + 1, 0));
  for (int i = 0; i < h; i++) {
    x.emplace_back(vector<int>());
    x.back().reserve(w + 1);
    x.back().push_back(0);
    for (int j = 1; j <= w; j++) {
      int x_elm;
      cin >> x_elm;
      x.back().push_back(x_elm);
    }
  }

  // horinzontal acc
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      x[i][j] += x[i][j - 1];
    }
  }
  // vertical acc
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      x[i][j] += x[i - 1][j];
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << x[c][d] + x[a - 1][b - 1] - x[c][b - 1] - x[a - 1][d] << "\n";
  }

  return 0;
}
