#include <bits/stdc++.h>
#define pp pair<int, int>
#define index first
#define value second

using namespace std;

int n;

vector<int> vec{ INT_MIN };
vector<pp> path;
stack<int> s;

void print_path() {
    int idx = vec.size() - 1;

    for (int i = path.size() - 1; i >= 0; --i) {
        if (path[i].index != idx)continue;
        s.push(path[i].value);
        idx--;
    }

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void make_sequence(int num) {
    int idx;
    if (num > vec.back()) {
        idx = vec.size();
        vec.push_back(num);
    }
    else {
        auto it = lower_bound(vec.begin(), vec.end(), num);
        idx = it - vec.begin();
        *it = num;
    }
    path.push_back({idx, num });
}
void solve() {
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        make_sequence(num);
    }
    cout << vec.size() - 1 << "\n";
    print_path();
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