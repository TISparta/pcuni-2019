#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> arr(n + 1), acc(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    acc[i] = acc[i - 1] + arr[i];
  }
  int sum = acc[n];
  if (sum % 3) {
    cout << 0 << endl;
    return (0);
  }
  sum /= 3;
  vector <int> pos;
  for (int i = 1; i <= n; i++) {
    if (acc[n] - acc[i - 1] == sum) {
      pos.push_back(i);
    }
  }
  int it = 0;
  long long ways = 0;
  for (int i = 1; i <= n; i++) {
    if (acc[i] == sum) {
      while (it < int(pos.size()) and i + 1 >= pos[it]) it++;
      if (it < int(pos.size()) and i + 1 < pos[it]) ways += int(pos.size()) - it;
    }
  }
  cout << ways << endl;
  return (0);
}