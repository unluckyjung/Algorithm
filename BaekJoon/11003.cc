#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool isValidIndex(int frontIndex, int indexPivot) {
    return frontIndex > indexPivot;
}
void solve() {
    int n, m;
    cin >> n >> m;

    deque<pii> dq;
    for (int idx = 0; idx < n; ++idx) {
        int num;
        cin >> num;

        while (!dq.empty() and dq.back().second >= num) {
            dq.pop_back();
        }
        dq.push_back({ idx, num });

        if (!isValidIndex(dq.front().first, idx - m)) {
            dq.pop_front();
        }
        cout << dq.front().second << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    solve();

    return 0;
}