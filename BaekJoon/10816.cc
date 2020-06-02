#include <bits/stdc++.h>
using namespace std;

#if 00
unordered_map<int, int> hash_m;

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
        hash_m[num]++;
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
        if (lower == vec.end()) {
            cout << 0 << " ";
            continue;
        }

        auto upper = upper_bound(vec.begin(), vec.end(), num);
        cout << upper - lower << " ";
    }
}

#endif

void Input() {
    int n;
    cin >> n;
    vec.resize(n);
    for (int& it : vec) {
        cin >> it;
    }
    sort(vec.begin(), vec.end());
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