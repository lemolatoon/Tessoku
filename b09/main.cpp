#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1500;
int n_overlap[MAX_SIZE + 3][MAX_SIZE + 3];
int main() {
  int n;
  cin >> n;

  // y
  // ^
  // | (c, b) --> (c, d)
  // |   |          |
  // | (a, b) --> (a, d)
  // o -----------------> x

  // input as differential
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a++;
    b++;
    c++;
    d++;
    // index: 0は番兵
    n_overlap[a][b]++;
    n_overlap[c][b]--;
    n_overlap[a][d]--;
    n_overlap[c][d]++;
  }

  // horizontal cumulative sum
  for (int i = 1; i <= MAX_SIZE; i++) {
    for (int j = 1; j <= MAX_SIZE; j++) {
      n_overlap[i][j] += n_overlap[i][j - 1];
    }
  }

  // vertical cumulative sum
  for (int i = 1; i <= MAX_SIZE; i++) {
    for (int j = 1; j <= MAX_SIZE; j++) {
      n_overlap[i][j] += n_overlap[i - 1][j];
    }
  }

  int sum = 0;
  for (int i = 1; i <= MAX_SIZE; i++) {
    for (int j = 1; j <= MAX_SIZE; j++) {
      if (n_overlap[i][j] > 0)
        sum++;
    }
  }

  cout << sum << "\n";

  return 0;
}
