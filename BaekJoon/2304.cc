
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int warehouse[MAX];
int n;
int min_idx, max_idx, max_height_idx;

int right_sum() {
    int sum = 0, h = 0;
    for (int i = max_idx; i > max_height_idx; --i) {
        h = max(h, warehouse[i]);
        sum += h;
    }
    return sum;
}

int left_sum() {
    int sum = 0, h = 0;
    for (int i = min_idx; i < max_height_idx; ++i) {
        h = max(h, warehouse[i]);
        sum += h;
    }
    return sum;
}

void solve() {
    int answer = warehouse[max_height_idx];
    cout << answer + left_sum() + right_sum();
}

void input() {
    cin >> n;
    int idx;
    while (n--) {
        cin >> idx;
        cin >> warehouse[idx];

        min_idx = min(min_idx, idx);
        max_idx = max(max_idx, idx);
        if (warehouse[idx] > warehouse[max_height_idx]) {
            max_height_idx = idx;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}