#include <bits/stdc++.h>

#define pp pair<int, int>
#define index first
#define value second 

using namespace std;

int t, n, want_document;

int priority_check(priority_queue<int> &pq, queue<pp> &printer) {
    int cnt = 1;
    while (!printer.empty()) {
        pp cur = printer.front(); printer.pop();

        if (cur.value == pq.top()){
            pq.pop();
            if (cur.index == want_document)return cnt;
            cnt++;
        }
        else printer.push(cur);
    }
}

void solve() {
    while (t--) {
        priority_queue<int> pq;
        queue<pp> printer;

        cin >> n >> want_document;
        int prior;

        for (int i = 0; i < n; ++i) {
            cin >> prior;
            printer.push({ i,prior });
            pq.push(prior);
        }
        cout << priority_check(pq, printer) << "\n";
    }
}

void input() {
    cin >> t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}