#include <bits/stdc++.h>
using namespace std;
int t, a, b;

void input() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL); cout.tie(NULL);
    input();

    return 0;
}