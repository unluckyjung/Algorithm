#include <bits/stdc++.h>
using namespace std;

int n ,subin;
int answer;

void solve() {
    int brother;
    for (int i = 0; i < n; ++i) {
        cin >> brother;
        if (i == 0) answer = abs(subin - brother);
        else {
            answer = gcd(answer, abs(subin - brother));
        }
    }
    cout << answer;
}

void input() {
    cin >> n >> subin;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();

    return 0;
}