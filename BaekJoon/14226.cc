#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int n;
bool visit[1002][1002];
queue<pp> q;

void _delete(int d, int c) {
    if (d > 0 and !visit[d - 1][c]) {
        visit[d - 1][c] = true;
        q.push({ d - 1 , c });
    }
}

void _paste(int d, int c) {
    if (c > 0 and d + c < 1002 and !visit[d + c][c]) {
        // 런타임 에러를 범위를 제한 (d+c < 1002) 함으로써 AC 받음.
        // TODO : 하지만, 더 커졌을때 뒤로 오는경우의 정당성을 증명하지 못함.
        visit[d + c][c] = true;
        q.push({ d + c , c });
    }
}

void _copy(int d) {
    if (!visit[d][d]) {
        visit[d][d] = true;
        q.push({ d, d });
    }
}

int bfs() {
    int time = 0;
    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            pp cur = q.front(); q.pop();
            int display = cur.first;
            int clipboard = cur.second;

            if (display == n) return time;

            _copy(display);
            _paste(display, clipboard);
            _delete(display, clipboard);
        }
        time++;
    }
    return -1;
}

void solve() {
    visit[1][0] = true;
    q.push({ 1,0 });

    cout << bfs();
}

void input() {
    cin >> n;
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