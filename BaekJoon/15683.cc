#if 01

#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

int board[9][9];
int n, m;
int answer = INT_MAX;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int dir_size[] = { -1,4,2,4,4,1 };
stack<pp> cctv;

void watch(int cur_x, int cur_y, int dir_x, int dir_y) {
    int nx = cur_x;
    int ny = cur_y;

    while (1) {
        nx += dir_x;
        ny += dir_y;

        if (nx < 0 or nx >= n or ny < 0 or ny >= m)return;
        if (board[nx][ny] == 6)return;

        if (board[nx][ny])continue;
        board[nx][ny] = board[cur_x][cur_y];
    }
}

int count_blind_spot() {
    int blind_spot_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == 0)   blind_spot_cnt++;
        }
    }
    return blind_spot_cnt;
}

void dfs() {
    if (cctv.empty()) {
        answer = min(answer, count_blind_spot());
        return;
    }

    pp cur = cctv.top(); cctv.pop();
    int cctv_kind = board[cur.x][cur.y];

    int save_board[9][9] = { 0 };
    memcpy(save_board, board, sizeof(board));
    
    int dir_max = dir_size[cctv_kind];

    for (int dir = 0; dir < dir_max; ++dir) {
        int dir_x;
        int dir_y;

        if (cctv_kind == 2) {
            for (int i = 0; i <= 2; i += 2) {
                dir_x = dx[(dir + i) % 4];
                dir_y = dy[(dir + i) % 4];
                watch(cur.x, cur.y, dir_x, dir_y);
            }
        }

        else {
            int k = cctv_kind - 2;
            if (cctv_kind == 1) k = 0;

            for (int i = 0; i <= k; i++) {
                dir_x = dx[(dir + i) % 4];
                dir_y = dy[(dir + i) % 4];
                watch(cur.x, cur.y, dir_x, dir_y);
            }
        }

        dfs();
        memcpy(board, save_board, sizeof(board));
	}

    cctv.push({ cur.x,cur.y });
}

void solve() {
    dfs();
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> board[i][ii];
            if (board[i][ii] == 0 || board[i][ii] == 6)continue;
            cctv.push({ i,ii });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();

    cout << answer;
    return 0;
}

#else

#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

int board[9][9];
int n, m;
int answer = INT_MAX;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int dir_size[] = { -1,4,2,4,4,1 };
stack<pp> cctv;

void watch(int cur_x, int cur_y, int dir_x, int dir_y) {
    int nx = cur_x;
    int ny = cur_y;

    while (1) {
        nx += dir_x;
        ny += dir_y;

        if (nx < 0 or nx >= n or ny < 0 or ny >= m)return;
        if (board[nx][ny] == 6)return;

        if (board[nx][ny])continue;
        board[nx][ny] = board[cur_x][cur_y];
    }
}

int count_blind_spot() {
    int blind_spot_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == 0)   blind_spot_cnt++;
        }
    }
    return blind_spot_cnt;
}

void dfs() {
    if (cctv.empty()) {
        answer = min(answer, count_blind_spot());
        return;
    }

    pp cur = cctv.top(); cctv.pop();
    int cctv_kind = board[cur.x][cur.y];

    int save_board[9][9] = { 0 };
    memcpy(save_board, board, sizeof(board));
    
    int dir_max = dir_size[cctv_kind];

    for (int dir = 0; dir < dir_max; ++dir) {
        int dir_x;
        int dir_y;

        if (cctv_kind == 2) {
            for (int i = 0; i <= 2; i += 2) {
                dir_x = dx[(dir + i) % 4];
                dir_y = dy[(dir + i) % 4];
                watch(cur.x, cur.y, dir_x, dir_y);
            }
        }

        else {
            int k = cctv_kind - 2;
            if (cctv_kind == 1) k = 0;

            for (int i = 0; i <= k; i++) {
                dir_x = dx[(dir + i) % 4];
                dir_y = dy[(dir + i) % 4];
                watch(cur.x, cur.y, dir_x, dir_y);
            }
        }

        dfs();
        memcpy(board, save_board, sizeof(board));
	}

    cctv.push({ cur.x,cur.y });
}

void solve() {
    dfs();
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> board[i][ii];
            if (board[i][ii] == 0 || board[i][ii] == 6)continue;
            cctv.push({ i,ii });
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

    cout << answer;
    return 0;
}

#endif