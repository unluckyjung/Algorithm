#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t;

void solve() {
    map<int, int> m;
    int n;  cin >> n;
    int num, answer = 0;
    while (n--) {
        cin >> num;
        m[num]++;
        if (m[num] == 1) answer++;
    }
    cout << answer << "\n";
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