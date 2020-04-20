#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

void solve() {
    int num;

    while (n--) {
        cin >> num;
        vec.push_back(num);
    }

    while (m--) {
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    
    for (int it : vec) {
        cout << it << " ";
    }
}

void input() {
    cin >> n >> m;
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