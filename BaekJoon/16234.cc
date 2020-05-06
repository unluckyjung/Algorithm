#if 01

#include <bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

int n, L, R;
int board[52][52];
bool visit[52][52];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

queue<pp> q;

bool Is_Moved() {

    vector<pp> team;
    int team_sum = 0;

    while (!q.empty()) {
        pp cur = q.front(); q.pop();

        int cur_people = board[cur.x][cur.y];
        team_sum += cur_people;
        team.push_back(cur);


        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
            if (visit[nx][ny]) continue;

            int nxt_people = board[nx][ny];
            int diff = abs(cur_people - nxt_people);

            if (diff < L or diff > R) continue;
            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    int team_cnt = team.size();
    if (team_cnt == 1) return false;

    int avg = team_sum / team_cnt;

    for (pp country : team) {
        board[country.x][country.y] = avg;
    }
    return true;
}

void Solve() {
    int answer = 0;

    while (1) {
        bool is_moved = false;
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < n; ++ii) {
                if (visit[i][ii]) continue;

                visit[i][ii] = true;
                q.push({ i,ii });
                if (Is_Moved() and !is_moved) is_moved = true;
            }
        }

        if (is_moved) answer++;
        else break;
    }
    cout << answer << "\n";
}

void Input() {
    cin >> n >> L >> R;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}

#else

#include <bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

int n, L, R;

int board[52][52];
bool visit[52][52];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };


queue<pp> q;

bool bfs() {
    queue<pp> team_q;
    int team_cnt = 0;
    int sum = 0;
    
    while (!q.empty()) {
        pp cur = q.front(); q.pop();
        team_q.push(cur);

        team_cnt++;
        sum += board[cur.x][cur.y];

        int cur_humans = board[cur.x][cur.y];

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
            if (visit[nx][ny]) continue;

            int nxt_humans = board[nx][ny];
            int diff = abs(cur_humans - nxt_humans);
            if (diff < L or diff > R) continue;

            visit[nx][ny] = true;
            q.push({ nx,ny });

        }
    }
    

    if (team_cnt == 1) return false;
    
    int avg = sum / team_cnt;

    while (!team_q.empty()) {
        pp cur = team_q.front(); team_q.pop();
        board[cur.x][cur.y] = avg;
    }

    return true;
}

void solve() {
    int human_move = 0;

    while (1) {
        bool moved = false;

        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < n; ++ii) {
                if (visit[i][ii])continue;
                visit[i][ii] = true;
                q.push({ i,ii });

                if (bfs()) moved = true;
            }
        }

        if (moved)  human_move++;
        else break;

        memset(visit, false, sizeof(visit));
    }

    cout << human_move << "\n";
}

void input() {
    cin >> n >> L >> R;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
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

#endif