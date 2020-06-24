#include <bits/stdc++.h>
using namespace std;

char board[1300][1300];
int n;

void PrintAnswer() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n - i; ++ii) {
            cout << board[i][ii];
        }
        cout << "\n";
    }
}

void Func(int s, int x, int y) {
    if (s == 1) {
        board[x][y] = '*';
        return;
    }
    
    int ns = s / 2;
    Func(ns, x, y);
    Func(ns, x + ns, y);
    Func(ns, x, y + ns);
}

void Solve() {
    Func(n, 0, 0);
    PrintAnswer();
}

void Init() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            board[i][ii] = ' ';
        }
    }
}

void Input() {
    cin >> n;
    n = 1 << n;
    Init();
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