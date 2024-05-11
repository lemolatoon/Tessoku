#include <bits/stdc++.h>
using namespace std;

const uint64_t mod = 998244353ul;
const uint64_t base = 100;

int main() {
  uint64_t n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<uint64_t> radixes;
  radixes.reserve(n);
  radixes.emplace_back(1);
  for (const auto i : views::iota(1ul, n)) {
    radixes.emplace_back((base * radixes.back()) % mod);
  }

  vector<uint64_t> hashes;
  hashes.reserve(n);
  hashes.emplace_back((s[0] - 'a') * radixes[0]);
  for (const auto i : views::iota(1ul, n)) {
    hashes.emplace_back((hashes.back() * base + (s[i] - 'a') * radixes[0]) %
                        mod);
  }

  // a * r^2 + b * r^1 + c * r^0;
  // a * r^0;
  // -> b * r^1 + c * r^0 = (a * r^2 + b * r^1 + c * r^0) - (a * r^0) * r^(2 - 1
  // + 1)
  const auto hasher = [&](size_t l, size_t r) {
    return (hashes[r] + mod -
            ((l == 0 ? 0 : hashes[l - 1]) * radixes[r - l + 1]) % mod) %
           mod;
  };

  for ([[maybe_unused]] const auto i : views::iota(0ul, q)) {
    uint64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    if (hasher(a, b) == hasher(c, d)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
