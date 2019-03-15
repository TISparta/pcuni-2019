#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector <ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = *max_element(begin(arr), end(arr));
    while (l != r) {
      int m = (l + r + 1) / 2;
      int cnt = 0;
      for (int elem: arr) cnt += elem / m;
      if (cnt >= k) l = m;
      else r = m - 1;
    }
    cout << l << endl;
  }
  return (0);
}