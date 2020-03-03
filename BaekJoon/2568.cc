#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

int n;
vector<int> LIS = { INT_MIN };
vector<pp> path, vec;

priority_queue<int, vector<int>, greater<int> > remove_pole;

void print_path() {
    int LIS_size = LIS.size() - 1;
    cout << n - LIS_size << "\n";

    for (int i = path.size() - 1; i >= 0; --i) {
        if (LIS_size == path[i].first) {
            LIS_size--;
            continue;
        }
        remove_pole.push(path[i].second);
    }

    while (!remove_pole.empty()) {
        cout << remove_pole.top() << "\n";
        remove_pole.pop();
    }
}

void make_LIS(int A_pole) {
    int order;
    if (A_pole > LIS.back()) {
        order = LIS.size();
        LIS.push_back(A_pole);
    }
    else {
        auto it = lower_bound(LIS.begin(), LIS.end(), A_pole);
        order = it - LIS.begin();
        *it = A_pole;
    }
    path.push_back({ order, A_pole });
}

void solve() {
    for (auto pole : vec) {
        make_LIS(pole.second);
    }
    print_path();
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
    //freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}