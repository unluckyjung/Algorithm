#include <bits/stdc++.h>
using namespace std;

int n;
char board[70][70];

bool IsFillSameThing(int x, int y, int len) {
    char base = board[x][y];
    for (int i = x; i < x + len; ++i) {
        for (int ii = y; ii < y + len; ++ii) {
            if (base == board[i][ii]) continue;
            return false;
        }
    }
    return true;
}

void MakeQuadTree(int x, int y, int len) {
    if (IsFillSameThing(x, y, len)) {
        cout << board[x][y];
        return;
    }
    cout << '(';
    
    int half = len / 2;
    MakeQuadTree(x, y, half);
    MakeQuadTree(x, y + half, half);
    MakeQuadTree(x + half, y, half);
    MakeQuadTree(x + half, y + half, half);

    cout << ')';
}

void Solve() {
    MakeQuadTree(0, 0, n);
}

void Input() {
    cin >> n;
    string line;
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int ii = 0; ii < n; ++ii) {
            board[i][ii] = line[ii];
        }
    }
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