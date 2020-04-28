#include <bits/stdc++.h>
using namespace std;

struct info {
    int x;
    int y;
    int dir;
};

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };
const int white = 0, red = 1, blue = 2;

info knight[12];

int board_color[14][14];
deque<int> board[14][14];

int n, k;

void Move(int k_num) {

    info cur = knight[k_num];

    if (board[cur.x][cur.y].front() != k_num) return;

    int nx = cur.x + dx[cur.dir];
    int ny = cur.y + dy[cur.dir];

    if (nx < 0 or nx >= n or ny < 0 or ny >= n or board_color[nx][ny] == blue) {
        cur.dir = (cur.dir + 2) % 4;
        knight[k_num].dir = cur.dir;

        nx = cur.x + dx[cur.dir];
        ny = cur.y + dy[cur.dir];

        if (nx < 0 or nx >= n or ny < 0 or ny >= n or board_color[nx][ny] == blue) return;
    }

    if (board_color[nx][ny] == red) reverse(board[cur.x][cur.y].begin(), board[cur.x][cur.y].end());

    while (!board[cur.x][cur.y].empty()) {
        int bottom_knight = board[cur.x][cur.y].front();
        board[cur.x][cur.y].pop_front();

        board[nx][ny].push_back(bottom_knight);
        knight[bottom_knight].x = nx;
        knight[bottom_knight].y = ny;
    }
    
}

int Solve() {
    int cnt = 0;

    while (1) {
        if (cnt >= 1000) return -1;
        cnt++;

        for (int i = 0; i < k; ++i) {
            Move(i);
            if ((int)board[knight[i].x][knight[i].y].size() >= 4) return cnt;
        }
    }

    return -1;
}

void Input() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board_color[i][ii];
        }
    }

    int a, b, c;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> c;

        if (c == 1) c = 1;
        else if (c == 2) c = 3;
        else if (c == 3) c = 0;
        else if (c == 4) c = 2;

        knight[i].x = --a;
        knight[i].y = --b;
        knight[i].dir = c;

        board[a][b].push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    cout << Solve() <<"\n";

    return 0;
}