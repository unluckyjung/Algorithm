#include <bits/stdc++.h>
#define ll long long
using namespace std;

int _gcd(const int &a, const int &b){
    if(b==0) return a;
    else return _gcd(b, a % b);
}

ll solution(int w, int h)
{
    ll t = (ll)w * h;
    int gcd = _gcd(w, h);
    return t - (w / gcd + h / gcd - 1) * gcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    cout << solution(100000000, 100000000);

    return 0;
}