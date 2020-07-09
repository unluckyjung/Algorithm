#include <bits/stdc++.h>

using namespace std;
int n, findR, findC;


#if 01
int Func(int curSize, int r, int c) {
    if (curSize == 0) return 0;

    int half = pow(2, curSize - 1);
    int cnt = half * half;

    if (r < half and c < half) return Func(curSize - 1, r, c);
    if (r < half and c >= half) return cnt + Func(curSize - 1, r, c - half);
    if (r >= half and c < half) return cnt * 2 + Func(curSize - 1, r - half, c);
    return cnt * 3 + Func(curSize - 1, r - half, c - half);
}

void Solve() {
    cout << Func(n, findR, findC);
}

#else

int answer;
int Func(int len, int r, int c) {
    if (r == findR and c == findC) return answer;

    if (r <= findR and c <= findC and findR < r + len and findC < c + len) {
        if (Func(len / 2, r, c)) return answer;
        if (Func(len / 2, r, c + len / 2)) return answer;
        if (Func(len / 2, r + len / 2, c)) return answer;
        if (Func(len / 2, r + len / 2, c + len / 2)) return answer;
    }

    answer += len * len;
    return 0;
}


void Solve() {
    cout << Func((int)pow(2, n), 0, 0);
}

#endif


void Input() {
    cin >> n >> findR >> findC;
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