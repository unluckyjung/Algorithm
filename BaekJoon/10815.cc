#include <bits/stdc++.h>
using namespace std;

#if 0
unordered_map<int, bool> hash_m;

void Solve() {
    int m;
    cin >> m;

    int num;
    while (m--) {
        cin >> num;
        cout << hash_m[num] << " ";
    }
}

void Input() {
    int n;
    cin >> n;

    int num;
    while (n--) {
        cin >> num;
        if (!hash_m[num]) hash_m[num] = true;
    }
}

#else

vector<int> vec;

void Solve() {
    int m;
    cin >> m;

    int num;
    while (m--) {
        cin >> num;
        auto lower = lower_bound(vec.begin(), vec.end(), num);
        auto upper = upper_bound(vec.begin(), vec.end(), num);
        cout << (lower == upper ? 0 : 1) << " ";
    }
}


void Input() {
    int n;
    cin >> n;
    vec.resize(n);
    for (int& it : vec) {
        cin >> it;
    }
    sort(vec.begin(), vec.end());
}

#endif


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}