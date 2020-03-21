#include <bits/stdc++.h>
using namespace std;

bool board[42][42];
bool sticker[12][12];
int n, m;
int s_n, s_m;
int k;


int get_answer() {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            if (board[i][ii]) ret++;
        }
    }
    return ret;
}

void rotate() {
    bool backup_sticker[12][12];
    memcpy(backup_sticker, sticker, sizeof(sticker));

    for (int i = 0; i < s_m; ++i) {
        for (int ii = 0; ii < s_n; ++ii) {
            sticker[i][ii] = backup_sticker[(s_n - 1) - ii][i];
        }
    }
    swap(s_n, s_m);

}

void attach(int i, int ii) {
    for (int x = i; x < i + s_n; ++x) {
        for (int y = ii; y < ii + s_m; ++y) {
            if (sticker[x - i][y - ii]) board[x][y] = true;
        }
    }
}

bool check(int i, int ii) {
    for (int x = i; x < i + s_n; ++x) {
        for (int y = ii; y < ii + s_m; ++y) {
            if (!sticker[x - i][y - ii])continue;
            if (board[x][y]) return false;
        }
    }
    attach(i, ii);
    return true;
}

bool try_attach() {
    for (int i = 0; i <= n - s_n; ++i) {
        for (int ii = 0; ii <= m - s_m; ++ii) {
            if (check(i, ii)) return true;
        }
    }
    return false;
}

void input_sticker() {
    memset(sticker, false, sizeof(sticker));
    cin >> s_n >> s_m;
    for (int i = 0; i < s_n; ++i) {
        for (int ii = 0; ii < s_m; ++ii)
            cin >> sticker[i][ii];
    }
}

void solve() {
    while (k--) {
        input_sticker();
        if (try_attach()) continue;
        for (int i = 0; i < 3; ++i) {
            rotate();
            if (try_attach()) break;
        }
    }
    cout << get_answer();
}

void input() {
    cin >> n >> m >> k;

    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}