#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MooLen[100];

char Solve(ll n) {
    if (n <= 3) {
        if (n == 1) return 'm';
        else return 'o';
    }

    ll m = 1;
    while (n > MooLen[m]) {
        m++;
    }

    if (n <= MooLen[m] - MooLen[m - 1]) {
        if (n - MooLen[m - 1] == 1) return 'm';
        else return 'o';
    }

    return Solve(n - MooLen[m - 1] - (m + 3));
}

void Input() {
    ll n;
    cin >> n;
    MooLen[0] = 3;
    for (ll i = 1; i < 100; ++i) {
        MooLen[i] = MooLen[i - 1] * 2 + (i + 3);
        if (MooLen[i] > 1e9) break;
    }
    cout << Solve(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();

    return 0;
}