#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int visit[MAX];
int num;

void prime_set() {
    for (int i = 2; i < MAX; ++i) {
        for (int ii = i; ii < MAX; ii+=i) {
            visit[ii]++;
        }
    }
}

void solve() {
    while (1) {
        cin >> num;
        if (num == 0)return;

        bool flag = true;
        for (int i = 3; i <= num; i+=2) {
            if (visit[i] != 1 || visit[num-i] != 1)continue;
            cout << num << " = " << i << " + " << num - i << "\n";
            flag = false;
            break;
        }
        if (flag) cout << "Goldbach's conjecture is wrong.\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    prime_set();
    solve();

    return 0;
}