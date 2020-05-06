#include<bits/stdc++.h>
#define MAX 1501
#define x first
#define y second
#define pp pair<int, int>

using namespace std;

int n, m;
char board[MAX][MAX];
bool swan_visit[MAX][MAX], water_visit[MAX][MAX];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

queue<pp> swan_q, water_q;


bool Find_Other_Swan() {

    vector<pp> nxt_swan;
    while (!swan_q.empty()) {
        pp cur = swan_q.front();    swan_q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (swan_visit[nx][ny]) continue;

            if (board[nx][ny] == 'L') return true;
  
            if (board[nx][ny] == 'X') {
                swan_visit[nx][ny] = true;
                nxt_swan.push_back({ nx, ny });
                continue;
            }
            swan_visit[nx][ny] = true;
            swan_q.push({ nx, ny });
        }
    }

    for (const pp &it : nxt_swan) {
        swan_q.push(it);
    }
    return false;
}

void Water_Bfs() {

    vector<pp> nxt_water;
    while (!water_q.empty()) {
        pp cur = water_q.front();    water_q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;
            if (water_visit[nx][ny])continue;

            if (board[nx][ny] == 'X') {
                water_visit[nx][ny] = true;
                board[nx][ny] = '.';
                nxt_water.push_back({ nx, ny });
                continue;
            }
            water_visit[nx][ny] = true;
            water_q.push({ nx, ny });
        }
    }

    for (const pp& it : nxt_water) {
        water_q.push(it);
    }

}

int Solve() {
    int cnt = 0;
    while (1) {
        if (Find_Other_Swan()) return cnt;
        cnt++;
        Water_Bfs();
    }
    return -1;
}

bool is_first_swan = true;

void Input() {
    cin >> n >> m;
    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int ii = 0; ii < m; ++ii) {
            board[i][ii] = line[ii];

            if (board[i][ii] == 'L') {
                if (is_first_swan) {
                    swan_visit[i][ii] = true;
                    swan_q.push({ i, ii });
                    is_first_swan = false;
                }
                else {
                    water_visit[i][ii] = true;
                    water_q.push({ i, ii });
                }
            }
            else if (board[i][ii] == '.') {
                water_visit[i][ii] = true;
                water_q.push({ i, ii });
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    cout << Solve();

    return 0;
}