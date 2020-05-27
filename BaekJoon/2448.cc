#include <bits/stdc++.h>
#define MAX (1024 * 3 + 2)
using namespace std;

int n;
char board[MAX][MAX * 2 - 1];

void Print_ans() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n * 2 - 1; ++ii) {
            if (board[i][ii] == '*') cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}

void Fill_Star(const int& x, const int& y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';

    for (int i = y - 2; i <= y + 2; ++i) {
        board[x + 2][i] = '*';
    }
}
void Func(const int& s, const int& x, const int& y) {
    if (s == 3) {
        Fill_Star(x, y);
        return;
    }

    int ns = s / 2;
    Func(ns, x, y);
    Func(ns, x + ns, y - ns);
    Func(ns, x + ns, y + ns);
}

void Solve() {
    Func(n, 0, n - 1);
    Print_ans();
}

void Input() {
    cin >> n;
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