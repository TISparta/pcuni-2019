#include <bits/stdc++.h>

using namespace std;

const int MX = 1e4 + 1;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector <vector <int>> G(MX);
  for (int i = 0; i < MX; i++) {
    for (int j = 0; j < MX; j++) {
      if (__builtin_popcount(i ^ j) == k) {
        G[i].push_back(j);
      }
    }
  }
  vector <int> frec(MX, 0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int elem: G[a]) {
      ans += frec[elem];
    }
    frec[a]++;
  }
  cout << ans << endl;
  return (0);
}