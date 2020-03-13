#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int dp1[MAX + 2], dp2[MAX + 2];
int arr[MAX + 2];

int N, answer = INT_MIN;

void make_dp1() {
	for (int n = 1; n <= N; ++n) {
		dp1[n] = max(dp1[n - 1] + arr[n], arr[n]);
        answer = max(answer, dp1[n]);
	}
}

void make_dp2() {
    for (int m = N; m >= 1; --m) {
        dp2[m] = max(dp2[m + 1] + arr[m], arr[m]);
    }
}

void solve() {
    make_dp1();
    make_dp2();

    for (int k = 1; k <= N - 2; ++k) {
        answer = max(answer, dp1[k] + dp2[k + 2]);
    }
    cout << answer << "\n";
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
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