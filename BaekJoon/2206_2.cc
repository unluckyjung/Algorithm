#include <bits/stdc++.h>
using namespace std;

int n, m;

int board[1002][1002];
int dist[1002][1002][2];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

const int CANT_GO = -1;

struct st {
    int x;
    int y;
    int skill;
};

int getAnswer() {
    int nonSkill = dist[n - 1][m - 1][0];
    int useSkill = dist[n - 1][m - 1][1];

    if (nonSkill == CANT_GO) return useSkill;
    else if (useSkill == CANT_GO) return nonSkill;
    else return min(nonSkill, useSkill);
}

void bfs() {
    queue<st> q;
    dist[0][0][0] = 1;
    q.push({ 0,0,0 });

    while (!q.empty()) {
        st cur = q.front(); q.pop();
        int curDist = dist[cur.x][cur.y][cur.skill];

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (board[nx][ny] == 1 and cur.skill == 0) {
                if (dist[nx][ny][1] != -1) continue;
                dist[nx][ny][1] = curDist + 1;
                q.push({ nx,ny,1 });
            }
            if (board[nx][ny] == 0) {
                if (dist[nx][ny][cur.skill] != -1) continue;
                dist[nx][ny][cur.skill] = curDist + 1;
                q.push({ nx,ny,cur.skill });
            }
        }
    }
}

void solve() {
    bfs();
    cout << getAnswer() << "\n";
}

void init() {
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int ii = 0; ii < m; ++ii) {
            board[i][ii] = line[ii] - '0';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    init();
    solve();

    return 0;
}