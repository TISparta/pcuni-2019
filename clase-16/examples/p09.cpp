#include <bits/stdc++.h>

using namespace std;

int N, n;
vector <vector <int>> sudoku;
vector <int> row, col, sq;
bool found;

int isZeroBit (int mask, int bit) {
  return ((mask >> bit) & 1) == 0;
}

void flipBit (int& mask, int bit) {
  mask ^= (1 << bit);
}

void backtrack (int r, int c) {
  if (found) return;
  if (r == N and c == 0) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << sudoku[i][j] << " \n"[j == N - 1];
      }
    }
    found = true;
    return;
  }
  int nr = r + (c == N - 1);
  int nc = (c + 1) == N ? 0 : c + 1;
  if (sudoku[r][c] != 0) {
    backtrack(nr, nc);
  }
  else {
    int id = (r / n) * n + (c / n);
    for (int d = 1; d <= N; d++) {
      if (isZeroBit(row[r], d) and
          isZeroBit(col[c], d) and
          isZeroBit(sq[id], d)) {
        sudoku[r][c] = d;
        flipBit(row[r], d);
        flipBit(col[c], d);
        flipBit(sq[id], d);
        backtrack(nr, nc);
        flipBit(row[r], d);
        flipBit(col[c], d);
        flipBit(sq[id], d);
        sudoku[r][c] = 0;
      }
    }
  }
}

int main () {
  bool first = true;
  while (cin >> n) {
    if (not first) cout << '\n';
    N = n * n;
    sudoku.resize(N, vector <int> (N, 0));
    row.resize(N, 0);
    col.resize(N, 0);
    sq.resize(N, 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> sudoku[i][j];
        row[i] |= (1 << sudoku[i][j]);
        col[j] |= (1 << sudoku[i][j]);
        sq[(i / n) * n + (j / n)] |= (1 << sudoku[i][j]);
      }
    }
    found = false;
    backtrack(0, 0);
    if (not found) cout << "NO SOLUTION\n";
    first = false;
    sudoku.clear();
    row.clear();
    col.clear();
    sq.clear();
  }
  return (0);
}
