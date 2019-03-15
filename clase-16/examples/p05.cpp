#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 25;

int n, m, grid[MAX_N][MAX_N];

void swapCols (int c1, int c2) {
  for (int r = 0; r < n; r++) swap(grid[r][c1], grid[r][c2]);
}

void read () {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j];
}

int main () {
  read();
  bool ok = false;
  for (int c1 = 0; c1 < m; c1++) {
    for (int c2 = c1; c2 < m; c2++) {
      swapCols(c1, c2);
      bool pib = true;
      for (int r = 0; r < n; r++) {
        int cnt = 0;
        for (int c = 0; c < m; c++) cnt += (grid[r][c] != (c + 1));
        if (cnt > 2) pib = false;
      }
      ok |= pib;
      swapCols(c1, c2);
    }
  }
  puts(ok ? "YES" : "NO");
  return (0);
}