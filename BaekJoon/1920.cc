#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

void Solve() {
    cin >> m;

    int num;
    while(m--) {
        cin >> num;
        cout << binary_search(vec.begin(), vec.end(), num) << "\n";
    }
}

void Input() {
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
    //freopen("input.txt", "r", stdin);

    Input();
    Solve();

    return 0;
}