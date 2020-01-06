#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y, a, b;
map<pair<int, int>, queue<pair<int, int>>> room;
queue<pair<int, int> > q;
int cnt = 1;

bool visit[101][101];
bool right_on[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void input()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y >> a >> b;
        room[{x-1, y-1}].push({ a-1,b-1 });
    }
}

void turn_on(int x, int y) {
    auto cur_room = room[{x, y}];
    while (!cur_room.empty()) {
        auto next_room = cur_room.front();
        cur_room.pop();
        right_on[next_room.first][next_room.second] = true;
    }
}

void bfs() {
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cnt++;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= n)continue;
            if (visit[nx][ny])continue;
            if (!right_on[nx][ny])continue;
            visit[nx][ny] = true;
            turn_on(nx, ny);
            q.push({ nx,ny });
        }
    }
}

void output() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            //if (visit[i][ii]) cout << "1";
            //else cout << "0";
            cout << right_on[i][ii];
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/ freopen("input.txt", "r", stdin);
    cin.tie(NULL);

    input();

    visit[0][0] = true;
    right_on[0][0] = true;
    turn_on(0, 0);
    q.push({0,0 });

    bfs();

    output();
    cout << cnt <<"\n";
    return 0;
}