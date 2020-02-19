#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int visit[MAX];
int n, m;


void prime_check(int s, int e) {
    for (int i = s; i <= e; ++i) {
        if (visit[i] == 1) {
            cout << i << "\n";
        }
    }
}

void solve() {
    for (int i = 2; i <= m; ++i) {
        for (int ii = i; ii <= m; ii += i) {
            visit[ii]++;
        }
    }
    prime_check(n, m);
}

void input() {
    cin >> n >> m;
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