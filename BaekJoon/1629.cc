#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a, b, c;

ll _pow(ll base, ll expo, ll mod) {
    if (expo == 0) return 1;
    
    ll ret = _pow(base, expo / 2, mod);

    ret = (ret * ret) % mod;

    if (expo % 2 != 0) {
        ret *= (base % mod);
        ret %= mod;
    }
    return ret;
}

void solve() {
    cout << _pow(a, b, c);
}

void input() {
    cin >> a >> b >> c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}