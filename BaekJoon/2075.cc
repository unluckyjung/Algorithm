#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  int n;
  cin >> n;

  int num;
  for (int i = 0; i < n; ++i) {
    for (int ii = 0; ii < n; ++ii) {
      cin >> num;
      pq.push(num);

      if (pq.size() > n) pq.pop();
    }
  }

  cout << pq.top();

  return 0;
}
