#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;

void Solve() {
    if (n & (ll)1) cout << "SK\n";
    else cout << "CY\n";
}

void Input() {
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}