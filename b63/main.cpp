#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t r, c;
  cin >> r >> c;

  pair<int64_t, int64_t> start_position;
  cin >> start_position.first >> start_position.second;
  start_position.first--;
  start_position.second--;
  pair<int64_t, int64_t> goal_position;
  cin >> goal_position.first >> goal_position.second;
  goal_position.first--;
  goal_position.second--;

  vector<string> board(r);

  for (const auto i : views::iota(0, r)) {
    cin >> board[i];
  }

  vector<vector<int64_t>> distances(r, vector<int64_t>(c, -1));
  queue<pair<int64_t, int64_t>> q;
  distances[start_position.first][start_position.second] = 0;
  q.emplace(start_position);

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (const auto [r_diff, c_diff] :
         {pair<int64_t, int64_t>{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
      const auto next_r = r + r_diff;
      const auto next_c = c + c_diff;
      if (board[next_r][next_c] == '#' || distances[next_r][next_c] != -1)
        continue;
      distances[next_r][next_c] = distances[r][c] + 1;
      q.emplace(pair{next_r, next_c});
    }
  }

  cout << distances[goal_position.first][goal_position.second] << endl;
  return 0;
}
