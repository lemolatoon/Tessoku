#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
int cord_count[N + 1][N + 1];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    cord_count[x][y]++;
  }

  // horizontal cumulative sum
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      cord_count[i][j] += cord_count[i][j - 1];
    }
  }

  // vertical cumulative sum
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      cord_count[i][j] += cord_count[i - 1][j];
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << cord_count[c][d] + cord_count[a - 1][b - 1] - cord_count[c][b - 1] -
                cord_count[a - 1][d]
         << "\n";
  }

  return 0;
}
