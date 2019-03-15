#include <bits/stdc++.h>

#define all(A) begin(A), end(A)

using namespace std;

const int MX = 1e6 + 10;

int main () {
  vector <int> ndiv(MX);
  for (int u = 1; u < MX; u++) for (int v = u; v < MX; v+= u) ndiv[v]++;
  vector <int> arr;
  arr.push_back(1);
  while (arr.back() < MX) {
    arr.push_back(arr.back() + ndiv[arr.back()]);
  }
  int tc;
  cin >> tc;
  int T = 0;
  while (tc--) {
    int l, r;
    cin >> l >> r;
    cout << "Case " << ++T << ": ";
    cout << upper_bound(all(arr), r) - lower_bound(all(arr), l) << '\n';
  }
  return (0);
}
