#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;

ll solve(int n) {
    int arr[101] = { 0 };
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int ii = i + 1; ii < n; ++ii) {
            sum += gcd(arr[i], arr[ii]);
        }
    }
    return sum;
}


void input() {
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);
    input();

    return 0;
}