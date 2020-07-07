#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;

void Solve() {
    if (n % (ll)(7) == 0 or n % (ll)7 == 2) cout << "CY\n";
    else cout << "SK\n";
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