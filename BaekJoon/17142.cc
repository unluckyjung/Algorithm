#include <bits/stdc++.h>
#define pp pair<int, int>
#define x first
#define y second

using namespace std;

queue<pp> q;
vector<pp> ready_virus;
vector<int> run_virus;

int board[52][52];
bool visited[52][52];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int n, m;
int empty_space;
int virus_num;

int answer = INT_MAX;

void Bfs() {

    int left_space = empty_space;
    int _time = 0;

    while (!q.empty()) {

        if (left_space == 0) {
            answer = min(answer, _time);
            return;
        }

        int q_size = q.size();
        while (q_size--) {
            auto cur = q.front(); q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                if (visited[nx][ny] or board[nx][ny] == 1) continue;

                if (board[nx][ny] == 0) left_space--;
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
        _time++;
    }
}


void Solve() {
    do {

        q = queue<pp>();
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < virus_num; ++i) {

            if (run_virus[i] == 0) continue;

            auto running_virus = ready_virus[i];
            visited[running_virus.x][running_virus.y] = true;
            q.push({ running_virus.x, running_virus.y });
        }

        Bfs();

    } while (prev_permutation(run_virus.begin(), run_virus.end()));

    if (answer == INT_MAX) cout << -1 << "\n";
    else cout << answer << "\n";
}

void Make_Bitmask() {
    for (int i = 0; i < m; ++i) {
        run_virus.push_back(1);
    }

    for (int i = 0; i < virus_num - m; ++i) {
        run_virus.push_back(0);
    }
}

void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
            if (board[i][ii] == 0) empty_space++;
            if (board[i][ii] != 2) continue;
            
            ready_virus.push_back({ i,ii });
        }
    }

    virus_num = (int)ready_virus.size();
    Make_Bitmask();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    
    Input();
    Solve();

    return 0;
}