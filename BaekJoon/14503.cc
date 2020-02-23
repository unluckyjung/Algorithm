#include <bits/stdc++.h>
#define MAX 51

using namespace std;

int board[MAX][MAX];
bool visit[MAX][MAX];

int n, m;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int answer = 1;
bool finished;

void dfs(int x, int y, int cmd);

void back_move(int x, int y, int cmd) {

    int dir = (cmd + 2) % 4;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (board[nx][ny]) {
        cout << answer << "\n";
        finished = true;
        return;
    }
    dfs(nx, ny, cmd);
}


void dfs(int x, int y , int cmd) {
    if (finished)return;

    bool can_clean = false;
    int dir;

    for (int i = 1; i <= 4; ++i) {
        dir = cmd - i;
        if (dir < 0) dir += 4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (board[nx][ny])continue;
        if (visit[nx][ny])continue;
        
        visit[nx][ny] = true;
        can_clean = true;
        answer++;
        dfs(nx, ny, dir);
        break;
    }

    if (!can_clean) {
        back_move(x, y ,cmd);
    }
}

void input() {
    cin >> n >> m;
    int start_x, start_y, cmd;
    cin >> start_x >> start_y >> cmd;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> board[i][ii];
        }
    }

    visit[start_x][start_y] = true;
    dfs(start_x, start_y, cmd);
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    return 0;
}