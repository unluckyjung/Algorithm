#include <bits/stdc++.h>

using namespace std;

int n, m, t;

vector<int> board[52];
bool visit[52][52];

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };


void delete_num() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (visit[i][ii]) board[i][ii] = 0;
        }
    }
}

int get_sum() {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            sum += board[i][ii];
        }
    }

    return sum;
}

double get_avg() {
    double sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == 0)continue;
            sum += board[i][ii];
            cnt++;
        }
    }

    return sum / cnt;
}

void average_set() {

    double avg = get_avg();

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii] == 0)continue;
            if (board[i][ii] < avg) board[i][ii]++;
            else if (board[i][ii] > avg) board[i][ii]--;
        }
    }
}

bool delete_check() {

    bool _delete = false;
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {

            if (board[i][ii] == 0)continue;

            bool deleted = false;
            
            for (int dir = 0; dir < 4; ++dir) {
                int nx = i + dx[dir];
                int ny = ii + dy[dir];

                if (nx < 0 or nx >= n)continue;
                if (ny < 0) ny += m;
                if (ny >= m) ny %= m;

                if (board[nx][ny] == 0)continue;
                if (board[nx][ny] == board[i][ii]) {
                    deleted = true;
                    visit[nx][ny] = true;
                }
            }
            if (deleted) {
                _delete = true;
                visit[i][ii] = true;
            }
        }
    }

    if (_delete) delete_num();

    return _delete;
}

void rotate(int k, int rotate_dir, int rotate_cnt) {
    
    int cnt = rotate_cnt % m;
    if (rotate_dir == 0) {
        rotate(board[k].rbegin(), board[k].rbegin() + cnt, board[k].rend());
    }
    else {
        rotate(board[k].begin(), board[k].begin() + cnt, board[k].end());
    }
}

void solve() {

    int a, rotate_dir, rotate_cnt;

    while (t--) {
        cin >> a >> rotate_dir >> rotate_cnt;

        int round_num = 0;
        while (1) {
            round_num += a;
            if (round_num - 1 >= n)  break;
            rotate(round_num - 1, rotate_dir, rotate_cnt);
        }

        if (!delete_check()) average_set();
    }

    cout << get_sum() << "\n";
}

void input() {
    cin >> n >> m >> t;

    int num;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cin >> num;
            board[i].push_back(num);
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