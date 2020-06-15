#include <bits/stdc++.h>
using namespace std;

struct spot {
    int cnt;
    int x, y;
};

struct cmp {
	bool operator()(const spot& a, const spot& b) {
        return a.cnt > b.cnt;
	}
};

priority_queue<spot, vector<spot>, cmp> pq;

char board[52][52];
bool visited[52][52];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int n;

int Dijstra() {
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.x == n - 1 and cur.y == n - 1) return cur.cnt;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;

            if (board[nx][ny] == '1') pq.push({ cur.cnt, nx, ny });
            else  pq.push({ cur.cnt + 1, nx, ny });
        }
    }
    return -1;
}

void Solve() {
    visited[0][0] = true;
    pq.push({ 0,0,0 });
    cout << Dijstra() << "\n";
}

void Input() {
    cin >> n;

    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int ii = 0; ii < n; ++ii) {
            board[i][ii] = line[ii];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}