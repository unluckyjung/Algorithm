#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

int n;
vector<int> LIS = { INT_MIN };
vector<pp> vec;

void make_LIS(int A_pole) {
    if (A_pole > LIS.back()) LIS.push_back(A_pole);
    else {
        auto it = lower_bound(LIS.begin(), LIS.end(), A_pole);
        *it = A_pole;
    }
}

void solve() {
    for (auto pole : vec) {
        make_LIS(pole.second);
    }
    int LIS_size = LIS.size() - 1;
    cout << n - LIS_size << "\n";
}

void input() {
    cin >> n;
    int A, B;
    for (int i = 0; i < n; ++i) {
        cin >> A >> B;
        vec.push_back({ B,A });
    }

    sort(vec.begin(), vec.end());
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