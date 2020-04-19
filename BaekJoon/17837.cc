#include <bits/stdc++.h>
using namespace std;

struct st {
    int x;
    int y;
    int dir;
};

int n, k;
int nx, ny;
int board[14][14];
const int White = 0, Red = 1, Blue = 2;

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,1,0,-1 };

stack<int> board_stack[14][14];
st status[12];
deque<int> tmp;

void push_new_spot(st cur) {

    if (nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == Blue) {
        nx = cur.x;
        ny = cur.y;
    }
    else if (board[nx][ny] == Red) reverse(tmp.begin(), tmp.end());

    while (!tmp.empty()) {
        int curr = tmp.front(); tmp.pop_front();
        status[curr].x = nx;
        status[curr].y = ny;
        board_stack[nx][ny].push(curr);
    }
}

void range_or_Blue_check(st& cur) {

    if (nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == Blue) {

        cur.dir = (cur.dir + 2) % 4;

        nx = cur.x + dx[cur.dir];
        ny = cur.y + dy[cur.dir];
    }
}

bool Init_check() {
    for (int i = 1; i <= k; ++i) {
        auto cur = status[i];
        if (board_stack[cur.x][cur.y].size() >= 4) return true;
    }
    return false;
}

int solve() {

    int cnt = 0;

    if (Init_check()) return 0;

    while (1) {
        cnt++;
        if (cnt > 1000) return -1;

        for (int i = 1; i <= k; ++i) {
            auto cur = status[i];

            while (1) {
                int TOP = board_stack[cur.x][cur.y].top();    board_stack[cur.x][cur.y].pop();
                tmp.push_front(TOP);
                if (TOP == i) break;
            }

            nx = cur.x + dx[cur.dir];
            ny = cur.y + dy[cur.dir];

            range_or_Blue_check(cur);
            push_new_spot(cur);

            status[i].x = nx;
            status[i].y = ny;
            status[i].dir = cur.dir;


            if (board_stack[nx][ny].size() >= 4) return cnt;
        }

    }

    return -1;
}

void input() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
        }
    }

    int a, b, c;
    for (int i = 1; i <= k; ++i) {
        cin >> a >> b >> c;
        status[i].x = a - 1;
        status[i].y = b - 1;

        if (c == 1) status[i].dir = 1;
        else if (c == 2) status[i].dir = 3;
        else if (c == 3) status[i].dir = 0;
        else if (c == 4) status[i].dir = 2;

        board_stack[status[i].x][status[i].y].push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    cout << solve() << "\n";

    return 0;
}