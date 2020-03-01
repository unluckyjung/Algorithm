#include <bits/stdc++.h>
using namespace std;

vector<int> vec = { INT_MIN };
int n;

void make_sequence(int num) {
    if (num > vec.back()) {
        vec.push_back(num);
    }
    else {
        auto it = lower_bound(vec.begin(), vec.end(), num);
        *it = num;
    }
}

void solve() {
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        make_sequence(num);
    }
    cout << vec.size() - 1 << " ";
}

void input() {
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();

    return 0;
}