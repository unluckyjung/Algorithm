#include <bits/stdc++.h>
#define MAX 1000001

int visit[MAX], t;
using namespace std;

void prime_set() {
    for (int i = 2; i < MAX; ++i) {
        for (int ii = i; ii < MAX; ii += i) {
            visit[ii]++;
        }
    }
}

int solve(int n) {
    int patition = 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (visit[i] != 1 or visit[n - i] != 1)continue;
        patition++;
    }
    return patition;
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

    prime_set();
    input();
    return 0;
}