#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> visited;
int n;

bool IsHappyNum(int n) {
    if (n == 1) return true;

    while (1) {
        int num = 0;

        while (n) {
            num += pow(n % 10, 2);
            n /= 10;
        }
        if (num == 1) return true;
        if (visited[num]) return false;
        visited[num] = true;
        n = num;
    }
    return true;
}

void Solve() {
    if (IsHappyNum(n)) cout << "HAPPY\n";
    else cout << "UNHAPPY\n";
}

void Input() {
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}