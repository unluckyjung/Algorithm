#include <bits/stdc++.h>
using namespace std;
 
int t;
 
void solve() {
    int x;
    cin >> x;
    cout << 1 << " " << x - 1 << "\n";
}
 
void input() {
    cin >> t;
    while (t--) {
        solve();
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    input();
 
    return 0;
}
