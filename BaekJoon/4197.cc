#include <bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

int n, m;
char board[1002][1002];
int jh_time[1002][1002], fire_time[1002][1002];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const char wall = '#';

queue<pp> jh_q, fire_q;

int Jh_Bfs() {

    while (!jh_q.empty()) {
        pp cur_jh = jh_q.front(); jh_q.pop();
        int cur_time = jh_time[cur_jh.x][cur_jh.y];

        if (cur_jh.x == 0 or cur_jh.y == 0 or cur_jh.x == n - 1 or cur_jh.y == m - 1) {
            return cur_time + 1;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur_jh.x + dx[dir];
            int ny = cur_jh.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (board[nx][ny] == wall) continue;
            if (jh_time[nx][ny] != -1) continue;
            if (fire_time[nx][ny] != -1 and fire_time[nx][ny] <= cur_time + 1) continue;

            jh_time[nx][ny] = cur_time + 1;
            jh_q.push({ nx,ny });
        }
    }

    return -1;
}

void Fire_Bfs() {

    while (!fire_q.empty()) {
        pp cur_f = fire_q.front(); fire_q.pop();
        int cur_time = fire_time[cur_f.x][cur_f.y];
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur_f.x + dx[dir];
            int ny = cur_f.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (board[nx][ny] == wall) continue;
            if (fire_time[nx][ny] != -1) continue;

            fire_time[nx][ny] = cur_time + 1;
            fire_q.push({ nx,ny });
        }
    }
}

void Solve() {
    Fire_Bfs();
    int result = Jh_Bfs();
    if (result == -1) cout << "IMPOSSIBLE\n";
    else cout << result << "\n";
}

void Input() {

    memset(jh_time, -1, sizeof(jh_time));
    memset(fire_time, -1, sizeof(fire_time));

    cin >> n >> m;

    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int ii = 0; ii < m; ++ii) {
            board[i][ii] = line[ii];
            if (board[i][ii] == 'J') {
                jh_time[i][ii] = 0;
                jh_q.push({ i,ii });
            }
            else if (board[i][ii] == 'F') {
                fire_time[i][ii] = 0;
                fire_q.push({ i,ii });
            }
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