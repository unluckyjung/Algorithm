#include<bits/stdc++.h>
#define MAX 1501
#define pp pair<int, int>
using namespace std;

int n, m;
char board[MAX][MAX];
bool L_visit[MAX][MAX];
bool C_visit[MAX][MAX];

bool find_answer;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;

queue<pp> Lq, Lnq;
queue<pp> Cq, Cnq;

bool fist_L;

void input() {
    cin >> n >> m;
    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int ii = 0; ii < m; ++ii) {
            board[i][ii] = line[ii];

            if (board[i][ii] == 'L') {
                if (!fist_L) {
                    L_visit[i][ii] = true;
                    Lq.push(make_pair(i, ii));
                    fist_L = true;
                }
                else {
                    C_visit[i][ii] = true;
                    Cq.push(make_pair(i, ii));
                }
            }
            else if (board[i][ii] == '.') {
                C_visit[i][ii] = true;
                Cq.push(make_pair(i, ii));
            }
        }
    }
}

void L_move() {
    while (!Lq.empty()) {
        pp cur = Lq.front();    Lq.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (L_visit[nx][ny])continue;

            if (board[nx][ny] == 'L') {
                find_answer = true;
                return;
            }

            if (board[nx][ny] == 'X') {
                L_visit[nx][ny] = true;
                Lnq.push(make_pair(nx, ny));
                continue;
            }
            L_visit[nx][ny] = true;
            Lq.push(make_pair(nx, ny));
        }
    }
    //Lq = Lnq;
    while (!Lnq.empty()) {
        Lq.push(Lnq.front());
        Lnq.pop();
    }
}

void C_bfs() {
    while (!Cq.empty()) {
        pp cur = Cq.front();    Cq.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (C_visit[nx][ny])continue;

            if (board[nx][ny] == 'X') {
                C_visit[nx][ny] = true;
                board[nx][ny] = '.';
                Cnq.push(make_pair(nx, ny));
                continue;
            }
            C_visit[nx][ny] = true;
            Cq.push(make_pair(nx, ny));
        }
    }
    //Cq = Cnq;
    //while (!Cnq.empty())  Cnq.pop();
    while (!Cnq.empty()) {
        Cq.push(Cnq.front());
        Cnq.pop();
    }
}

int solve() {
    while (1) {
        L_move();
        if (find_answer) return cnt;
        cnt++;
        C_bfs();
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    input();
    cout << solve();

    return 0;
}