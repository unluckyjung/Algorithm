#include <bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

int n, m, time_cnt, cheese_cnt;
queue<pp> air_q, cheese_q;

int board[101][101];
bool air_visit[101][101];
int cheese_visit[101][101];

bool find_answer;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void melt() {
    while (!cheese_q.empty()) {
        pp cur = cheese_q.front(); cheese_q.pop();
        cheese_visit[cur.x][cur.y]++;

        if (cheese_visit[cur.x][cur.y] == 2) {
            board[cur.x][cur.y] = 0;
            cheese_cnt--;
            if (cheese_cnt == 0) {
                find_answer = true;
                return;
            }
        }
    }
}

void init() {
    memset(air_visit, false, sizeof(air_visit));
    memset(cheese_visit, false, sizeof(cheese_visit));
}

void bfs() {
    while (!air_q.empty()) {
        pp cur = air_q.front(); air_q.pop();
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (air_visit[nx][ny])continue;
            if (board[nx][ny]) {
                cheese_q.push({ nx,ny });
                continue;
            }
            air_visit[nx][ny] = true;
            air_q.push({ nx,ny });
        }
    }
}

int solve() {
    while (!find_answer) {
        time_cnt++;
        init();
        air_visit[0][0] = true;
        air_q.push({ 0,0 });
        bfs();
        melt();
    }
    return time_cnt;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> board[i][ii];
            if (board[i][ii])cheese_cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    cout << solve();
    return 0;
}