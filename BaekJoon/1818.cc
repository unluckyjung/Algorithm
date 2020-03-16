#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec{ INT_MIN };

void make_LIS(int num) {
    if (num > vec.back())   vec.push_back(num);
    else {
        auto it = lower_bound(vec.begin(), vec.end(), num);
        *it = num;
    }
}

void solve() {
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        make_LIS(num);
    }
    cout << n - vec.size() + 1 << "\n";
}

void input() {
    cin >> n;
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