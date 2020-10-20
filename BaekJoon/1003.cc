#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

pii fiboDP[42] = { {1,0}, {0,1} };

void solve() {
    for (int i = 2; i <= 40; ++i) {
        fiboDP[i].first = fiboDP[i - 1].first + fiboDP[i - 2].first;
        fiboDP[i].second = fiboDP[i - 1].second + fiboDP[i - 2].second;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;  cin >> n;
        cout << fiboDP[n].first << " " << fiboDP[n].second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();

    return 0;
}