#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[101][101][4];
bool rail[101][101];

int f_x, f_y, f_dir;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
//  북 , 동 , 남, 서
//  + 시계방향 , - 반시계방향

int answer = INT_MAX;

struct robot {
    int x, y;
    int dir;
};

queue<robot> q;


int change_real_dir(int n) {
    if (n == 1)return 1;
    else if (n == 2) return 3;
    else if (n == 3) return 2;
    else if (n == 4) return 0;
}

void input() {
    memset(dist, -1, sizeof(dist));

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> rail[i][ii];
        }
    }

    robot s_robot;
    int dir;

    cin >> s_robot.x >> s_robot.y >> dir;

    s_robot.x--, s_robot.y--;

    s_robot.dir = change_real_dir(dir);
    dist[s_robot.x][s_robot.y][s_robot.dir] = 0;
    q.push(s_robot);

    cin >> f_x >> f_y >> f_dir;
    f_x--, f_y--;
    f_dir = change_real_dir(f_dir);
}


void solve() {
    while (!q.empty()) {
        robot cur = q.front(); q.pop();
        if (cur.x == f_x && cur.y == f_y) {
            if (cur.dir == f_dir) answer = dist[f_x][f_y][cur.dir];
            else {
                int ret = abs(cur.dir - f_dir);
                answer = dist[f_x][f_y][cur.dir] + ret;
            }
            return;
        }

        for (int i = 1; i <= 3; ++i) {
            int nx = cur.x + dx[cur.dir] * i;
            int ny = cur.y + dy[cur.dir] * i;
            if (nx < 0 or nx >= n or ny < 0 or ny >= m)break;
            if (rail[nx][ny])break;
            if (dist[nx][ny][cur.dir] != -1)continue;   //이미 갔었던곳이면 넘어갈뿐.
            dist[nx][ny][cur.dir] = dist[cur.x][cur.y][cur.dir] + 1;

            robot tmp;
            tmp.x = nx, tmp.y = ny, tmp.dir = cur.dir;
            q.push(tmp);
        }

        for (int rot = 1; rot <= 3; ++rot) {
            int next_rot = cur.dir + rot;
            next_rot %= 4;
            if (dist[cur.x][cur.y][next_rot] != -1)continue;

            if (rot == 2) dist[cur.x][cur.y][next_rot] = dist[cur.x][cur.y][cur.dir] + 2;
            else dist[cur.x][cur.y][next_rot] = dist[cur.x][cur.y][cur.dir] + 1;

            robot tmp;
            tmp.x = cur.x, tmp.y = cur.y, tmp.dir = next_rot;
            q.push(tmp);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);

    input();
    solve();
    cout << answer;

    return 0;
}