#include <bits/stdc++.h>
using namespace std;

int n, answer[3];
int board[2200][2200]; // 3 ^ 7 = 2189

void PaperCountUp(int x, int y) {
    int paperKind = board[x][y];
    answer[paperKind + 1]++;
}

bool IsAllSame(int x, int y, int len) {
    int base = board[x][y];
    for (int i = x; i < x + len; ++i) {
        for (int ii = y; ii < y + len; ++ii) {
            if (board[i][ii] == base) continue;
            return false;
        }
    }
    return true;
}

void PaperCheck(int x, int y, int len) {
    if (IsAllSame(x, y, len)) {
        PaperCountUp(x, y);
        return;
    }

    int AThird = len / 3;
    for (int i = 0; i < 3; ++i) {
        for (int ii = 0; ii < 3; ++ii) {
			PaperCheck(x + i * AThird, y + ii * AThird, AThird);
		}
    }
}

void Solve() {
    PaperCheck(0, 0, n);
    for (const int &paperKind : answer) {
        cout << paperKind << "\n";
    }
}

void Input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> board[i][ii];
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