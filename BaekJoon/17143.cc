#include <bits/stdc++.h>
#define spot pair<int,int>
using namespace std;

struct shark {
    int speed;
    int dir;
    int _size;
};

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

shark water[102][102];
bool visit[102][102];


queue<pair<spot, shark>> move_q;

int n, m, shark_n;

void Get_New_Spot() {
    while (!move_q.empty()) {
        auto cur = move_q.front(); move_q.pop();
        spot cur_spot = cur.first;
        shark cur_shark = cur.second;

        if (visit[cur_spot.first][cur_spot.second]) {
            shark spot_shark = water[cur_spot.first][cur_spot.second];
            if (spot_shark._size > cur_shark._size) continue;
        }
        visit[cur_spot.first][cur_spot.second] = true;
        water[cur_spot.first][cur_spot.second] = cur_shark;
    }
}

void Move(int x, int y, shark k) {
    int cur_dir = k.dir;
    int nx = x;
    int ny = y;

    for (int i = 0; i < k.speed; ++i) {
        nx = nx + dx[cur_dir];
        ny = ny + dy[cur_dir];

        if (nx < 0 or nx >= n or ny < 0 or ny >= m) {
            cur_dir = (cur_dir + 2) % 4;
            nx = nx + dx[cur_dir] * 2;
            ny = ny + dy[cur_dir] * 2;
        }
    }

    k.dir = cur_dir;

    move_q.push({ {nx,ny}, k });
}

void Shark_Move() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (!visit[i][ii]) continue;
            visit[i][ii] = false;
            Move(i, ii, water[i][ii]);
        }
    }
    Get_New_Spot();
}


void Solve() {
    int answer = 0;

    for (int king = 0; king < m; ++king) {
        for (int i = 0; i < n; ++i) {
            if (!visit[i][king])continue;
            visit[i][king] = false;
            answer += water[i][king]._size;
            break;
        }
        Shark_Move();
    }

    cout << answer << "\n";
}

void Input() {
    cin >> n >> m >> shark_n;

    int s_x, s_y, s, d, z;

    for (int i = 0; i < shark_n; ++i) {
        cin >> s_x >> s_y >> s >> d >> z;

        if (d == 1) d = 0;
        else if (d == 2) d = 2;
        else if (d == 3) d = 1;
        else if (d == 4) d = 3;

        s_x--, s_y--;
        water[s_x][s_y].dir = d;

        if (d == 0 or d == 2) s = s % ((n - 1) * 2);
        else s = s % ((m - 1) * 2);

        water[s_x][s_y].speed = s;
        water[s_x][s_y]._size = z;
        visit[s_x][s_y] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}