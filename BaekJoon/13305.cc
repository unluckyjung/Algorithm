#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

vector<int> cityPrice;
vector<int> dists;

void sol() {
  ll answer = 0;
  ll curPrice = cityPrice[0];
  ll movedDist = 0;

  for (int i = 1; i < n; ++i) {
    int nextPrice = cityPrice[i];
    movedDist += dists[i - 1];
    if (nextPrice < curPrice) {
      answer += movedDist * curPrice;
      movedDist = 0;
      curPrice = nextPrice;
    }
  }

  if (movedDist != 0) {
    answer += movedDist * curPrice;
  }

  cout << answer << "\n";
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("input.txt", "r", stdin);

  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int dist;
    cin >> dist;
    dists.push_back(dist);
  }

  for (int i = 0; i < n; ++i) {
    int price;
    cin >> price;
    cityPrice.push_back(price);
  }

  sol();

  return 0;
}
