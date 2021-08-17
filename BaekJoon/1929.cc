#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

int visited[MAX];
int n, m;

void primeCheck(int s, int e) {
  for (int i = s; i <= e; ++i) {
    if (visited[i] == 1) {
      cout << i << "\n";
    }
  }
}

void solve() {
  for (int i = 2; i <= m; ++i) {
    for (int ii = i; ii <= m; ii += i) {
      visited[ii]++;
    }
  }
  primeCheck(n, m);
}

void input() {
  cin >> n >> m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
//  freopen("input.txt", "r", stdin);

  input();
  solve();

  return 0;
}