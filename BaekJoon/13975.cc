#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  while (t--) {
    int bookPageCount;
    ll cost = 0;
    priority_queue<ll, vector<ll>, greater<>> pq;

    cin >> bookPageCount;

    while (bookPageCount--) {
      int bookPage;
      cin >> bookPage;
      pq.push(bookPage);
    }

    while (pq.size() >= 2) {
      ll page1 = pq.top();
      pq.pop();
      ll page2 = pq.top();
      pq.pop();
      cost += page1 + page2;
      pq.push(page1 + page2);
    }
    cout << cost << "\n";
  }

  return 0;
}
