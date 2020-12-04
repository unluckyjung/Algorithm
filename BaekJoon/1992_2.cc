#include <bits/stdc++.h>
using namespace std;

string board[66];

bool isFillsamething(int size, int x, int y) {
    char base = board[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int ii = y; ii < y + size; ++ii) {
            if (board[i][ii] != base) return false;
        }
    }
    return true;
}

void quardTree(int size, int x, int y) {
    if (size == 1 or isFillsamething(size, x, y)) {
        cout << board[x][y];
        return;
    }

    int half = size / 2;
    cout << '(';
    quardTree(half, x, y);
    quardTree(half, x, y + half);
    quardTree(half, x + half, y);
    quardTree(half, x + half, y + half);
    cout << ')';
}


void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    quardTree(n, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    solve();

    return 0;
}