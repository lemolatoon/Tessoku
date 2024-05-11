#include <bits/stdc++.h>
using namespace std;

typedef __uint128_t uint128_t;

const uint128_t base = 100;
const uint128_t mod = (static_cast<uint128_t>(1ul << 61) - 1);

int main() {
  int64_t n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<uint128_t> radixes;
  radixes.reserve(n);
  radixes.emplace_back(1);
  for (const auto i : views::iota(0, n)) {
    radixes.emplace_back((radixes.back() * base) % mod);
  }

  vector<uint128_t> hashes;
  hashes.reserve(n);
  hashes.emplace_back(s[0] - 'a');
  for (const auto i : views::iota(1, n)) {
    hashes.emplace_back((hashes.back() * base + (s[i] - 'a')) % mod);
  }

  vector<uint128_t> hashRev;
  string sRev = s;
  std::reverse(sRev.begin(), sRev.end());
  hashRev.reserve(n);
  hashRev.emplace_back(sRev[0] - 'a');
  for (const auto i : views::iota(1, n)) {
    hashRev.emplace_back((hashRev.back() * base + (sRev[i] - 'a')) % mod);
  }

  const auto hasher = [&](int64_t l, int64_t r, vector<uint128_t> &preHash) {
    if (l == 0)
      return preHash[r];
    auto ret =
        (preHash[r] + mod - (preHash[l - 1] * radixes[r - l + 1]) % mod) % mod;

    return ret;
  };

  const auto indexReverse = [&](int64_t i) { return n - i - 1; };
  for ([[maybe_unused]] const auto i : views::iota(0, q)) {
    int64_t l, r;
    cin >> l >> r;
    l--;
    r--;
    bool pred;
    if (l == r) {
      pred = true;
    } else if ((l + r) % 2 == 0) {
      // 2,8
      // -> 2,4 | 6,8
      const auto lForward = l;
      const auto rForward = (r + l) / 2 - 1;
      const auto lBackward = indexReverse(r);
      const auto rBackward = indexReverse((r + l) / 2 + 1);
      pred = hasher(lForward, rForward, hashes) ==
             hasher(lBackward, rBackward, hashRev);
    } else {
      // 2,9
      // -> 2,5 | 6,9
      const auto lForward = l;
      const auto rForward = (r + l) / 2;
      const auto lBackward = indexReverse(r);
      const auto rBackward = indexReverse((r + l) / 2 + 1);
      pred = hasher(lForward, rForward, hashes) ==
             hasher(lBackward, rBackward, hashRev);
    }
    if (pred) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
