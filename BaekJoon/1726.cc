#include <bits/stdc++.h>
using namespace std;

struct Robot {
    int x, y;
    int dir, cnt;
};

const int dx[] = { 0,0,0,1,-1 };
const int dy[] = { 0,1,-1,0,0 };

int board[103][103];
bool visit[103][103][5];

queue<Robot> q;

int n, m;
int end_x, end_y, end_dir;
int answer;

void go_straight(Robot &cur) {
    int nx, ny;
    for (int move_cnt = 1; move_cnt <= 3; ++move_cnt) {
        nx = cur.x + dx[cur.dir] * move_cnt;
        ny = cur.y + dy[cur.dir] * move_cnt;

        if (nx < 1 or nx > n or ny < 1 or ny > m)return;
        if (board[nx][ny] == 1)return;

        if (visit[nx][ny][cur.dir])continue;

        visit[nx][ny][cur.dir] = true;
        q.push({ nx,ny,cur.dir, cur.cnt + 1 });
    }
}

void rotate(Robot &cur) {

	if (cur.dir <= 2) {
		for (int n_dir = 3; n_dir <= 4; ++n_dir) {
            if (visit[cur.x][cur.y][n_dir])continue;
			visit[cur.x][cur.y][n_dir] = true;
			q.push({ cur.x, cur.y, n_dir, cur.cnt + 1 });
		}
	}
	else {
        for (int n_dir = 1; n_dir <= 2; ++n_dir) {
            if (visit[cur.x][cur.y][n_dir])continue;
            visit[cur.x][cur.y][n_dir] = true;
            q.push({ cur.x, cur.y, n_dir, cur.cnt + 1 });
        }
	}
}


int bfs() {
    while (!q.empty()) {
        Robot cur = q.front(); q.pop(); 

        if (cur.x == end_x && cur.y == end_y && cur.dir == end_dir) {            
            return cur.cnt;
        }

        go_straight(cur);
        rotate(cur);
    }
}

void init() {
    int s_x, s_y, s_d;
    cin >> s_x >> s_y >> s_d;

    visit[s_x][s_y][s_d] = true;
    q.push({ s_x, s_y, s_d, 0 });

    cin >> end_x >> end_y >> end_dir;
}

void solve() {
    cout << bfs() << "\n";
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int ii = 1; ii <= m; ++ii) {
            cin >> board[i][ii];
        }
    }
    init();
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