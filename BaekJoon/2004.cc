#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;

int five_counter(int k) {
    int cnt = 0;
    for (ll i = 5; i <= k; i *= 5) {
        cnt += k / i;
    }
    return cnt;
}

int two_counter(int k) {
    int cnt = 0;
    for (ll i = 2; i <= k; i *= 2) {
        cnt += k / i;
    }
    return cnt;
}

int solve() {
    int two = two_counter(n) - two_counter(n - m) - two_counter(m);
    int five = five_counter(n) - five_counter(n - m) - five_counter(m);
    return min(two, five);
}
void input() {
    cin >> n >> m;
    cout << solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();

    return 0;
}