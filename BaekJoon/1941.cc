#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

char board[5][5];

bool visit[5][5];
bool can_go[5][5];
vector<int> vec;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n = 5;
int answer;


void bfs(int sx, int sy) {
    queue<pp> q;
    visit[sx][sy] = true;
    q.push({ sx,sy });
    int move_cnt = 1;

    while (!q.empty()) {
        pp cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= n)continue;
            if (!can_go[nx][ny])continue;
            if (visit[nx][ny])continue;

            move_cnt++;
            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    if (move_cnt == 7)answer++;
}

void solve() {
    for (int i = 0; i < 25; ++i) {
        if (i < 25 - 7)vec.push_back(0);
        else vec.push_back(1);
    }

    do {
        int y_count = 0;
        memset(can_go, false, sizeof(can_go));
        memset(visit, false, sizeof(visit));

        int start_x, start_y;
        for (int i = 0; i < 25; ++i) {
            if (vec[i] != 1)continue;

            int x = i / n;
            int y = i % n;

            if (board[x][y] == 'Y') y_count++;

            can_go[x][y] = true;
            start_x = x;
            start_y = y;
        }
        if (y_count >= 4) continue;
        
        bfs(start_x, start_y);

    } while (next_permutation(vec.begin(), vec.end()));

    cout << answer << "\n";
}

void input() {
    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int ii = 0; ii < n; ++ii) {
            board[i][ii] = line[ii];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();

    return 0;
}