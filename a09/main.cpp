#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1500;
int n_yuki[MAX_SIZE + 2][MAX_SIZE + 2];
int main() {
  int h, w, n;
  cin >> h >> w >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    n_yuki[a][b]++;
    n_yuki[c + 1][d + 1]++;
    n_yuki[a][d + 1]--;
    n_yuki[c + 1][b]--;
  }

  // horizontal cumulative sum
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w + 1; j++) {
      n_yuki[i][j] += n_yuki[i][j - 1];
    }
  }

  // vertical cumulative sum
  for (int i = 1; i <= h + 1; i++) {
    for (int j = 1; j <= w + 1; j++) {
      n_yuki[i][j] += n_yuki[i - 1][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << n_yuki[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
