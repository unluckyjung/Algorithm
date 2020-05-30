#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> vec;
int n;

void Solve() {
    ll answer = 0;

    for (int rank = 1; rank <= n; ++rank) {
        int want_rank = vec[rank - 1];
        answer += abs(rank - want_rank);
    }
    cout << answer << "\n";
}

void Input() {
    cin >> n;
    vec.resize(n);

    for (int& want_rank : vec) {
        cin >> want_rank;
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