#include <bits/stdc++.h>

using namespace std;

int a, b, q, l, r;
vector <int> div_a, div_b;

int getAnswer(int l, int r) {
    for (const int& d : div_a) {
        if (d > r) continue;
        if (d < l) return -1;
        if (binary_search(begin(div_b), end(div_b), d)) return d;
    }
    return -1;
}

void getDivisors(int num, vector <int>& div) {
    for (int d = 1; d * d <= num; d++)
        if (num % d == 0) div.push_back(d), div.push_back(num / d);
    sort(begin(div), end(div));
}

int main() {
    cin >> a >> b;
    getDivisors(a, div_a);
    getDivisors(b, div_b);
    reverse(begin(div_a), end(div_a));
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << getAnswer(l, r) << endl;
    }
    return (0);
}