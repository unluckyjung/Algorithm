#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

int board[102][102];
bool visit[102][102];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, break_cnt;
queue<pp> cur_q, nxt_q;


bool bfs() {
    while (!cur_q.empty()) {
        auto cur = cur_q.front();   cur_q.pop();
        if (cur.x == n - 1 and cur.y == m - 1) return true;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (visit[nx][ny])continue;
            if (board[nx][ny] == 1) {
                visit[nx][ny] = true;
                nxt_q.push({ nx,ny });
            }
            else {
                visit[nx][ny] = true;
                cur_q.push({ nx,ny });
            }
        }
    }

    cur_q = nxt_q;
    nxt_q = queue<pp>();
    break_cnt++;
    return false;
}

void solve() {
    visit[0][0] = true;
    cur_q.push({ 0,0 });

    while (!cur_q.empty()) {
        if (bfs()) break;
    }

    cout << break_cnt << "\n";

}

void input() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int ii = 0; ii < m ; ++ii) {
            board[i][ii] = line[ii]-'0';
        }
    }

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