#include <bits/stdc++.h>
using namespace std;

int n;
int answer;

void solve() {
    cin >> n;
    answer = n / 5 + n / 25 + n / 125;
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);
    solve();

    return 0;
}