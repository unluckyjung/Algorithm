#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    if (n == 1)cout << "B\n";
    else cout << "A\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    solve();

    return 0;
}