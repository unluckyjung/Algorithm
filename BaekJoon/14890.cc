#if 01

#include <bits/stdc++.h>
using namespace std;

int n, runway_len;
int board[204][102];

bool go_check(int i) {
    int before_h = board[i][0];
    int flat_cnt = 1;

    for (int ii = 1; ii < n; ++ii) {
        int cur_h = board[i][ii];

        if (before_h == cur_h) flat_cnt++;
        else if (abs(before_h - cur_h) > 1) return false;

        else if (before_h < cur_h) {
            if (flat_cnt < runway_len)  return false;
            flat_cnt = 1;
        }

        else if (before_h > cur_h) {
            if (flat_cnt < 0)   return false;
            flat_cnt = 1 - runway_len;
        }

        before_h = cur_h;
    }

    if (flat_cnt < 0)return false;
    else return true;
}

int solve() {
    int way_cnt = 0;
    for (int i = 0; i < n * 2; ++i) {
        if (go_check(i))    way_cnt++;
    }
    return way_cnt;
}

void init() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            board[n + i][ii] = board[(n - 1) - ii][i];
        }
    }
}

void input() {
    cin >> n >> runway_len;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii)  cin >> board[i][ii];
    }
    init();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    cout << solve();

    return 0;
}

#else

#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int n, len;
int answer;

void solve() {
    for (int i = 0; i < n * 2; ++i) {
        int before = board[i][0];
        int flat_cnt = 0;
        bool flag = true;

        for (int ii = 0; ii < n; ++ii) {
            if (board[i][ii] == before) flat_cnt++;

            else if (abs(board[i][ii] - before) >= 2) {
                flag = false;
                break;
            }

            else if (before > board[i][ii]) {
                if (flat_cnt < 0) {
                    flag = false;
                    break;
                }

                before = board[i][ii];
                flat_cnt = 1 - len;
            }

            else if (before < board[i][ii]) {
                if (flat_cnt < len) {
                    flag = false;
                    break;
                }

                before = board[i][ii];
                flat_cnt = 1;
            }
        }
        if (flag) {
            if (flat_cnt >= 0)answer++;
        }
    }

    cout << answer << "\n";
}

void input() {
    cin >> n >> len;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii)   cin >> board[i][ii];
    }

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            board[n + i][ii] = board[ii][i];
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

    return 0;
}

#endif