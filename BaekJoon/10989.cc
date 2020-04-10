#include <bits/stdc++.h>
#define MAX 10002

using namespace std;

int arr[MAX];
int n;

void solve() {
    for (int i = 1; i < MAX; ++i) {
        if (arr[i] == 0)continue;

        for (int cnt = 0; cnt < arr[i]; ++cnt) {
            cout << i << "\n";
        }
    }
}

void input() {
    cin >> n;
    int num;
    while (n--) {
        cin >> num;
        arr[num]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}