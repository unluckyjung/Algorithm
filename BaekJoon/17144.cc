#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int n, m, t;

vector<pp> marchine;
queue<pp> dust_q;

int room[52][52];
int save_dust[52][52];

int Left_Dust() {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (room[i][ii] == -1)continue;
            ret += room[i][ii];
        }
    }
    return ret;
}

void Run_Machine() {

    for (int i = 0; i < 2; ++i) {
        queue<int> q;
        q.push(0);

        int dir = 0;
        pp cur = marchine[i];

        while (!q.empty()) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m) {
                if (i == 0) dir -= 1;
                else dir += 1;

                if (dir < 0) dir += 4;
                if (dir >= 4) dir %= 4;

                nx = cur.x + dx[dir];
                ny = cur.y + dy[dir];
            }

            if (room[nx][ny] == -1) break;

            q.push(room[nx][ny]);
            room[nx][ny] = q.front();
            cur.x = nx, cur.y = ny;
            q.pop();
        }
    }
}

void Add_Dust() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            room[i][ii] += save_dust[i][ii];
        }
    }
}

void Spread_Dust(const int &i, const int &ii) {

    int cnt = 0;
    int dust_vol = room[i][ii] / 5;

    for (int dir = 0; dir < 4; ++dir) {
        int nx = i + dx[dir];
        int ny = ii + dy[dir];

        if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
        if (room[nx][ny] == -1) continue;
        cnt++;
        save_dust[nx][ny] += dust_vol;
    }

    room[i][ii] -= dust_vol * cnt;
}


void Find_Dust() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (room[i][ii] == 0 or room[i][ii] == -1) continue;
            Spread_Dust(i, ii);
        }
    }
}

void Solve() {

    while (t--) {
        memset(save_dust, 0, sizeof(save_dust));
        Find_Dust();
        Add_Dust();
        Run_Machine();
    }
    cout << Left_Dust() << "\n";
}

void Input() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> room[i][ii];
            if (room[i][ii] != -1) continue;
            marchine.push_back({ i,ii });
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