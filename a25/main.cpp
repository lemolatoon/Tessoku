#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
  int64_t h, w;
  cin >> h >> w;

  vector<vector<char>> board(h, vector<char>(w));

  for (const auto i : views::iota(0, h)) {
    string tmp;
    cin >> tmp;
    for (const auto j : views::iota(0, w)) {
      board[i][j] = tmp[j];
    }
  }

  // num_pathes[i][j]: the number of pathes to reach (0, 0) -> (i, j) in the
  // board.
  vector<vector<int64_t>> num_pathes(h, vector<int64_t>(w, -1));
  for (const auto i : views::iota(0, h)) {
    for (const auto j : views::iota(0, w)) {
      if (i == 0 && j == 0) {
        num_pathes[0][0] = 1;
        continue;
      }
      if (board[i][j] == '#') {
        num_pathes[i][j] = 0;
        continue;
      }
      array<int64_t, 2> n_prev_path = {0, 0};
      if (i - 1 >= 0) {
        n_prev_path[0] = num_pathes[i - 1][j];
      }

      if (j - 1 >= 0) {
        n_prev_path[1] = num_pathes[i][j - 1];
      }
      num_pathes[i][j] = n_prev_path[0] + n_prev_path[1];
    }
  }

  cout << num_pathes[h - 1][w - 1] << endl;

  return 0;
}
