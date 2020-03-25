#include <bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

int n, m;
int board[52][52];
bool visit[52][52];

const int dx[] = { -1,-1,-1, 1, 1, 1, 0, 0 };
const int dy[] = { -1, 0, 1,-1, 0, 1,-1, 1 };

queue<pp> q;

void bfs() {
    while (!q.empty()) {
        pp cur = q.front(); q.pop();
        for (int dir = 0; dir < 8; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (board[nx][ny] == 0 or visit[nx][ny])continue;
            
            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

void solve() {
    int island_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == 0 or visit[i][ii])continue;
            visit[i][ii] = true;
            q.push({ i,ii });
            bfs();

            island_cnt++;
        }
    }
    cout << island_cnt << "\n";
}

void input() {
    while (1) {
        cin >> m >> n;
        if (n + m == 0)return;
        
        memset(board, 0, sizeof(board));
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < m; ++ii) {
                cin >> board[i][ii];
            }
        }
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}