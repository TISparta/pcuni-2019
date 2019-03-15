#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> arr;

void generate (string num, int it = 0) {
  if (it == 11) return;
  if (not num.empty()) arr.push_back(stoll(num));
  generate(num + "4", it + 1);
  generate(num + "7", it + 1);
}

int main () {
  generate("", 0);
  sort(begin(arr), end(arr));
  ll l, r;
  cin >> l >> r;
  int pos = 0;
  while (arr[pos] < l) pos++;
  ll ans = (min(r, arr[pos]) - l + 1) * arr[pos];
  l = arr[pos] + 1;
  while (l <= r) {
    pos++;
    ans += (min(r, arr[pos]) - l + 1) * arr[pos];
    l = arr[pos] + 1;
  }
  cout << ans << endl;
  return (0);
}