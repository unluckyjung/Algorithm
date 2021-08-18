#include <bits/stdc++.h>
#define ll long long

using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;
ll n, m;

ll solve();

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  cin >> n >> m;

  while (n--) {
    ll num;
    cin >> num;
    pq.push(num);
  }

  cout << solve() << "\n";

  return 0;
}

ll solve() {
  ll answer = 0;

  while (m--) {
    ll smallCard1 = pq.top();
    pq.pop();
    ll smallCard2 = pq.top();
    pq.pop();

    ll sum = smallCard1 + smallCard2;
    pq.push(sum);
    pq.push(sum);
  }
  while (!pq.empty()) {
    answer += pq.top();
    pq.pop();
  }
  return answer;
}
