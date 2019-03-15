#include <bits/stdc++.h>
 
using namespace std;
 
const int SIZE = 1 << 10;
 
int main () {
  int n;
  vector <int> frec(SIZE, 0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    string num;
    cin >> num;
    int mask = 0;
    for (char ch: num) mask |= (1 << (ch - '0'));
    frec[mask]++;
  }
  long long ans = 0;
  for (int i = 0; i < SIZE; i++) {
    if (frec[i] > 1) ans += 1LL * frec[i] * (frec[i] - 1) / 2;
    for (int j = i + 1; j < SIZE; j++) {
      if (i & j) ans += 1LL * frec[i] * frec[j];
    }
  }
  cout << ans << '\n';
  return (0);
}