#include <bits/stdc++.h>
using namespace std;

const int MAX = 2200; // 3^7 = 2187
int board[MAX][MAX];
int answer[3];

bool isAllSameNumber(int size, int x, int y) {
    int base = board[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int ii = y; ii < y + size; ++ii) {
            if (board[i][ii] != base) return false;
        }
    }
    return true;
}

void paperCounter(int size, int x, int y) {
    int base = board[x][y];
    if (size == 1 or isAllSameNumber(size, x, y)) {
        answer[base + 1]++;
        return;
    }

    int div = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int ii = 0; ii < 3; ++ii) {
            paperCounter(div, x + div * i, y + div * ii);
        }
    }
}

void input(int n) {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    input(n);
    paperCounter(n, 0, 0);
    for (int ans : answer) {
        cout << ans << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    solve();

    return 0;
}