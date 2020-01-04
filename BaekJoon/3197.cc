#include<bits/stdc++.h>
using namespace std;

int n, m;
char board[1501][1501];
bool b_visit[1501][1501];
bool w_visit[1501][1501];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;

queue<pair<int, int> > bq;
queue<pair<int, int> > bnq;

queue<pair<int, int> > wq;
queue<pair<int, int> > wnq;

bool fist_L;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> board[i][ii];

            if (board[i][ii] == 'L') {
                if (!fist_L) {
                    b_visit[i][ii] = true;
                    bq.push(make_pair(i, ii));
                    fist_L = true;
                }
                else {
                    w_visit[i][ii] = true;
                    wq.push(make_pair(i, ii));
                }
            }
            else if (board[i][ii] == '.') {
                w_visit[i][ii] = true;
                wq.push(make_pair(i, ii));
            }
        }
    }
}

void output() {
    cout << "\n\n";
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cout << board[i][ii];
        }
        cout << "\n";
    }
}


void b_bfs() {

    while (!bq.empty()) {
        pair<int, int> cur = bq.front();    bq.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (b_visit[nx][ny])continue;

            if (board[nx][ny] == 'L') {
                cout << cnt << "\n";
                exit(0);
            }

            if (board[nx][ny] == 'X') {
                b_visit[nx][ny] = true;
                bnq.push(make_pair(nx, ny));
                continue;
            }
            b_visit[nx][ny] = true;
            bq.push(make_pair(nx, ny));
        }
    }
    bq = bnq;
    while (!bnq.empty())  bnq.pop();
}

void sink() {
    while (!wq.empty()) {
        pair<int, int> cur = wq.front();    wq.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (w_visit[nx][ny])continue;

            if (board[nx][ny] == 'X') {
                w_visit[nx][ny] = true;
                board[nx][ny] = '.';
                wnq.push(make_pair(nx, ny));
                continue;
            }
            w_visit[nx][ny] = true;
            wq.push(make_pair(nx, ny));
        }
    }
    wq = wnq;
    while (!wnq.empty())  wnq.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    while (1) {
        //output();
        b_bfs();
        cnt++;
        sink();
    }
    return 0;
}