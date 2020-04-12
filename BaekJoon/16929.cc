#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[52][52];
bool visit[52][52];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int s_x, s_y;

void Init() {
    memset(visit, false, sizeof(visit));
}

bool dfs(int x, int y, int cur) {
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
        if (nx == s_x and ny == s_y and cur >= 4) {
            return true;
        }
        if (visit[nx][ny] or board[nx][ny] != board[x][y]) continue;

        visit[nx][ny] = true;
        if(dfs(nx, ny, cur + 1)) return true;
        //이전에 return dfs(nx, ny, cur+1) 로 해놨어서 원하는 값이 안 나왔다.
        //dfs중 하나라도 막힌곳이 나온경우 false를 리턴하고 dfs를 종료하게 되므로 문제가 발생한다.
    }
    return false;
}

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            visit[i][ii] = true;
            s_x = i;
            s_y = ii;

            if (dfs(i, ii, 1)) {
                cout << "Yes\n";
                return;
            }
            Init();
        }
    }
    cout << "No\n";
    return;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string line; cin >> line;
        for (int ii = 0; ii < m; ++ii) {
            board[i][ii] = line[ii];
        }
    }
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