#include <bits/stdc++.h>
using namespace std;

const int MAX = 6600; // 6600 > pow(3,8)
bool board[MAX][MAX];

void func(int n, int x, int y) {
    if (n == 1) {
        board[x][y] = true;
        return;
    }

    int div = n / 3;
    for (int i = 0; i < 3; ++i) {
        for (int ii = 0; ii < 3; ++ii) {
            if (i == 1 and ii == 1) continue;
            func(div, x + i * div, y + ii * div);
        }
    }
}

void printAnswer(int n) {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            if (board[i][ii]) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void solve() {
    int n;
    cin >> n;
    func(n, 0, 0);
    printAnswer(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    solve();

    return 0;
}