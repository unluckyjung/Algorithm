#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3, b1, b2, b3;

void solve() {
    int a = a1 ^ a2;
    a = a ^ a3;

    int b = b1 ^ b2;
    b = b ^ b3;

    cout << a << " " << b << "\n";
}

void input() {
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
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